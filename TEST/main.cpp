#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *longestCommonPrefix (char **strs, int strsSize) {
    if (strsSize == 1) {
        return strs[0];
    }

    int *len = (int *) malloc(sizeof(int) * strsSize);
    int minSizeLoc = 0;
    for (int i = 0; i < strsSize; i++) {
        len[i] = strlen(strs[i]);
        if (len[i] < len[minSizeLoc]) {
            minSizeLoc = i;
        }
    }

    char *base = (char *) malloc(sizeof(char) * 201);
    strcpy(base, strs[minSizeLoc]);
    int len_base = strlen(base);

    for (int i = 0; i < strsSize; i++) {
        if (i == minSizeLoc) {
            continue;
        }
        char *target = strs[i];

        for (int j = 0; j < len_base; j++) {
            if (base[j] != target[j]) {
                len_base = j;
                break;
            }
        }

        if (len_base == 0) {
            strcpy(base, "");
            return base;
        } else {
            strncpy(base, target, len_base);
            base[len_base] = '\0';
        }
    }
    return base;
}

int main () {
    char *str[3];
    for (int i = 0; i < 3; ++i) {
        str[i] = (char *) malloc(10);
    }
    strcpy(str[0], "flower");
    strcpy(str[1], "flow");
    strcpy(str[2], "flight");
    puts(longestCommonPrefix(str, 3));
    return 0;
}


/*
 //给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//
//
//L0 → L1 → … → Ln - 1 → Ln
//
//
// 请将其重新排列后变为：
//
//
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//
//
// 示例 1：
//
//
//
//
//输入：head = [1,2,3,4]
//输出：[1,4,2,3]
//
// 示例 2：
//
//
//
//
//输入：head = [1,2,3,4,5]
//输出：[1,5,2,4,3]
//
//
//
// 提示：
//
//
// 链表的长度范围为 [1, 5 * 10⁴]
// 1 <= node.val <= 1000
//
//
// Related Topics 栈 递归 链表 双指针 👍 1047 👎 0


//leetcode submit region begin(Prohibit modification and deletion)






//leetcode submit region end(Prohibit modification and deletion)

 */