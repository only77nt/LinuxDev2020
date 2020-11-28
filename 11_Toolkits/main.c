#include <stdio.h>
#include <string.h>
#include <glib.h>

#define BUFFER_SIZE 80

gboolean finder(gpointer key, gpointer value, gpointer user_data) {
	return !g_ascii_strcasecmp(key, user_data);
}

void print_map_iterator(gpointer key, gpointer value, gpointer user_data) {
    printf("%s%s%d\n", (gchar*)key, (char*)user_data, *(gint*)value);
}

void print_list_iterator(gpointer key, gpointer map) {
    gpointer value = g_hash_table_find(map, (GHRFunc)finder, key);
    printf("%s:%d\n", (gchar*)key, *(gint*)value);
}

int main(int argc, char* argv[argc]) {
    FILE* input;
    switch (argc)
    {
    case 1:
        input = stdin;
        break;
    case 2:
        input = fopen(argv[1], "r");
		if (!input) {
			printf("Error: Can't open file \"%s\"\n", argv[1]);
			return 1;
		}
        break;
    default:
        printf("Error: write filename or nothing as a program params\n");
        return 1;
    }

    gchar buffer[BUFFER_SIZE+1];

    GSList* list = NULL, *node;

    GHashTable* map = g_hash_table_new(g_str_hash, g_int_equal);

    while (fgets(buffer, BUFFER_SIZE+1, input)) {
        buffer[strlen(buffer) - 1] = '\0';
		gchar** words = g_strsplit(buffer, " ", BUFFER_SIZE);

        for (int i = 0; words[i]; i++) {
            gpointer item_ptr = g_hash_table_find(map, (GHRFunc)finder, words[i]);
            if (!item_ptr) {
                gint* tmp = g_new(gint, 1);
				*tmp = 1;
                gchar* strtmp = g_strdup(words[i]);
				g_hash_table_insert(map, strtmp, tmp);
                g_hash_table_lookup(map, words[i]);
				list = g_slist_append(list, strtmp);
            } else {
				(*(gint*)item_ptr)++;
			}
        }
    }

    //g_hash_table_foreach(map, print_map_iterator, ":");

    GSList* result = NULL;
    int len = g_slist_length(list);

    for(int i = 0; i < len; i++){
        gint max = 0;
        char* maxNode = NULL;
        for(node = list; node; node = node->next){
            //printf("%s ", (char*)node->data);
            gpointer item_ptr = g_hash_table_find(map, (GHRFunc)finder, node->data);

            if (max < *(gint*)item_ptr){
                max = *(gint*)item_ptr;
                maxNode = (char*)node->data;
            }
        }
        //printf("\n");
        result = g_slist_append(result, maxNode);
        list = g_slist_remove(list, maxNode);
    }

    g_slist_foreach(result, print_list_iterator, map);
	
	g_hash_table_destroy(map);
	g_slist_free(list);
    g_slist_free(result);
   
    return 0;
}