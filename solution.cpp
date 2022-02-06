
#include<iostream>
/*
 * Max chars : 26
 */

#define MAX_CHARS 26
#define MAX_BUF_LEN 256

struct Status
{
    int index;
    int value;
    Status()
    {
        index = -1;
        value = 0;
    }
};
struct TrieNode
{ 
    int value;
    TrieNode *childern[MAX_CHARS];
    TrieNode() {
        value = -1;
        for (int i = 0; i < MAX_CHARS; i++)
            childern[i] = NULL;
    }
    TrieNode(int val) {
        value = val;
        for (int i = 0; i < MAX_CHARS; i++)
            childern[i] = NULL;
    }
};
 
class Trie
{ 
    private: 
        TrieNode *root;
    public: 
        Trie()
        { 
            root = getTrieNode(0);
        }
 
        TrieNode *getTrieNode(int val) 
        {   
            TrieNode *tnode = new TrieNode(val);
            return tnode;
        }
 
        void insert(const char* str, int val) 
        { 
            TrieNode *cur = root; 
            for (int i = 0; i < strlen(str); i++)
            {
                if (!cur->childern[str[i] - 'a']) 
                    cur->childern[str[i] - 'a'] = getTrieNode(0);
                cur = cur->childern[str[i] - 'a']; 
            }
            cur->value = val;
        }
 
        void searchInternal(TrieNode *cur, const char* str, 
                            int len, int i, Status* status) 
        { 
            //std::cout << "\ntesting i = " << i << std::endl;
            if (cur) { 
                //std::cout << "i=" << i << " " << cur->value << ":" << cur->value << " " ;
                if (i < strlen(str)) {
                    if (cur->childern[str[i] - 'a'] != NULL)
                        return searchInternal
            (cur->childern[str[i] - 'a'], str, len, i + 1, status);
                    
                } 
                status->index = i;
                status->value = cur->value;
                //std::cout << "\ncur " << cur->value << std::endl;
                return;
            }
            return;
        }
 
        void search(const char* str, Status* status) 
        { 
            int len = strlen(str);
            if (len > 0 && str[0] >= 'a' && root) {
                if (root->childern[str[0] - 'a'] == NULL) {
                    //std::cout << root->value;
                    status->index = -1;
                    status->value = 0;
                    return;
                }
                return searchInternal(root->childern[str[0] - 'a'], 
                                      str, len, 1, status);
            }
            status->index = -1;
            status->value = 0;
            return;
        }
        void readDataFromFile()
        {
            int ret = 0;
            char word[256] = "";
            int value = 0;
            FILE* fp = fopen("value.txt", "r+");
            ret = fscanf(fp, "%s %d\n", word, &value);
            while(ret != EOF)
            {
                this->insert(word, value);
                ret = fscanf(fp, "%s %d\n", word, &value);
            }
            fclose(fp);
        }
};
int main(int argc, char* argv[]) 
{ 
    Trie trieData;
    trieData.readDataFromFile();
    int total = 0;
    std::string input;
    Status status;
    input = "hacker";
    trieData.search(input.c_str(), &status);
    total += status.value;
    int t = 0;
    std::string str1 = input;
    while(status.index != -1 && t < 4) {
        std::string str2 = str1.substr(status.index);
        //std::cout << "str2 " << "[" << str2 << "]" << std::endl;
        status.index = -1;
        status.value = 0;
        trieData.search(str2.c_str(), &status);
        //std::cout << "\ni=" << status.index << " v=" << status.value << std::endl;
        total += status.value;
        str1 = str2;
        t++;
    }
    std::cout << "total = " << total << std::endl;
    return 0;
}