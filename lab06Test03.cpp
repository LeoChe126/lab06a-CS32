#include "WordCount.h"
#include "tddFuncs.h"

int main(){
    WordCount test;
    test.incrWordCount("leo");
    test.incrWordCount("leo");
    test.incrWordCount("nick");
    ASSERT_EQUALS(2, test.getNumUniqueWords());
    ASSERT_EQUALS(1, test.decrWordCount("leo"));
    ASSERT_EQUALS(1, test.getWordCount("leo"));
    ASSERT_EQUALS(0, test.decrWordCount("leo"));
    ASSERT_EQUALS(-1, test.decrWordCount("leo"));
    ASSERT_EQUALS(0, test.getWordCount("leo"));
    ASSERT_EQUALS(1, test.getTotalWords());
    ASSERT_EQUALS(1, test.getNumUniqueWords());
    ASSERT_EQUALS(-1, test.decrWordCount("grace"));
    return 0;
}