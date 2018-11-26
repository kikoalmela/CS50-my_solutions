/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// define size of hash table
#define HASHTABLE_SIZE 65536

// create node for words in linked lists
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// create hash table
node *hashtable[HASHTABLE_SIZE];

// Hash function via reddit user delipity: https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASHTABLE_SIZE;
}

// set variable to store number of words in dictionary
int dic_size = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // allocate memory for a copy of word
    char *copy = malloc(strlen(word) + 1);
    if (copy == NULL) {
        unload();
        return false;
    }

    // make copy
    strcpy(copy, word);

    // convert copy to lowercase
    for (int i = 0, l = strlen(copy); i < l; i++)
    {
        if (isupper(copy[i]))
        {
            copy[i] = tolower(copy[i]);
        }
    }

    // find the index of hashtable where the word would be
    int hash = hash_it(copy);

    // set a pointer to the head of the linked list at that index
    node *cursor = hashtable[hash];

    // search moving the cursor through that linked list
    while (cursor != NULL)
    {
        if (strcmp(copy, cursor->word) == 0)
        {
            free(copy);
            return true;
        }
        cursor = cursor->next;
    }

    // if the word is not found, clean memory and return false
    free(copy);
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // set to NULL the heads of hashtable
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // open dictionary file and check for unsuccessfull case
    FILE *dp = fopen(dictionary, "r");
    if (dp == NULL)
    {
        fprintf(stderr, "dictionary couldn't be opened\n");
        return false;
    }

    // create storage for word
    char word[LENGTH + 1];

    // load words from dictionary
        // scan dictionary word by word
    while (fscanf(dp, "%s", word) != EOF)
    {
        // increment number of words
        dic_size++;

        // malloc a node *for new word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        // copy word into node
        strcpy(new_node->word, word);

        // set hash, the index of hashtable for current word, with the hash function
        int hash = hash_it(word);

        // if it is the first word in the linked list, point hashtable[hash] to the new node
        if (hashtable[hash] == NULL)
        {
            new_node->next = NULL;
            hashtable[hash] = new_node;
        }
        // else, insert new word node in the linked list
        else
        {
            node *tmp = new_node;
            new_node->next = hashtable[hash];
            hashtable[hash] = tmp;
        }
    }

    // close file
    fclose(dp);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (dic_size > 0)
    {
        return dic_size;
    }
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // loop through the hashtable
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        // asign a node pointer to the first element of the linked list
        node *cursor = hashtable[i];

        // loop through the elements of the linked list
        while (cursor != NULL)
        {
            // asign a temporary node pointer to de current element
            node *temp = cursor;
            // advance the cursor to the next element
            cursor = cursor->next;
            // free the temporary node pointer
            free(temp);
        }
    }
    return true;
}
