#include "WordCount.h"
#include "tddFuncs.h"

int main(){
    WordCount test;
    ASSERT_EQUALS(0, test.getTotalWords());
    ASSERT_EQUALS(0, test.getNumUniqueWords());
    test.incrWordCount("12mOnkEYs-$");
    ASSERT_EQUALS(1, test.getTotalWords());
    ASSERT_EQUALS(1, test.getWordCount("monkeys"));
    ASSERT_EQUALS(0, test.getWordCount("leo"));
    test.incrWordCount("leo");
    test.incrWordCount("cristian");
    test.incrWordCount("sam");
    ASSERT_EQUALS(4, test.getTotalWords());
    test.incrWordCount("grace");
    ASSERT_EQUALS(5, test.getTotalWords());
    ASSERT_EQUALS(5, test.getNumUniqueWords());
    return 0;
}
