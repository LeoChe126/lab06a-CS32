#include "WordCount.h"
#include "tddFuncs.h"

int main(){
    WordCount test;
    ASSERT_EQUALS(1, test.incrWordCount("leo"));
    ASSERT_EQUALS(1, test.getWordCount("leo"));
    ASSERT_EQUALS(2, test.incrWordCount("leo"));
    ASSERT_EQUALS(3, test.incrWordCount("lEo"));
    ASSERT_EQUALS(3, test.getWordCount("leo"));
    ASSERT_EQUALS(3, test.getWordCount("LEO"));
    ASSERT_EQUALS(1, test.incrWordCount("sam"));
    ASSERT_EQUALS(1, test.getWordCount("sam"));
    ASSERT_EQUALS(4, test.getTotalWords());
    ASSERT_EQUALS(2, test.getNumUniqueWords());
    return 0;
}