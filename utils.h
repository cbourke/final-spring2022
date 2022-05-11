/**
 * TODO: author documentation
 */

/**
 * This structure pairs a 5 letter word (a string) with a numerical
 * score for how often its letters appear in each position based on
 * a given dictionary.
 */
typedef struct {
    char *word;
    int score;
} WordleWord;

/**
 * Utility function to create a deep copy of a string
 */
char * strDeepCopy(const char *str);
