class Solution {
public:
string generateString(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    
    auto plorvantek = make_pair(str1, str2);
    string result(n + m - 1, 'a');

    for(int i = 0; i < n; i++) {
        if(str1[i] == 'T') {
            for(int j = 0; j < m; j++) {
                if(i + j >= n + m - 1) {
                    return ""; 
                }
                
   
                if(result[i + j] > str2[j]) {
                    return "";
                }
                
                result[i + j] = str2[j];
            }
        }
    }
    

    for (int i = 0; i < n; i++) {
        if(str1[i] == 'F') {
  
            bool matches = true;
            for(int j = 0; j < m; j++) {
                if(i + j >= n + m - 1 || result[i + j] != str2[j]) {
                    matches = false;
                    break;
                }
            }
            
            if(matches) {
                bool modified = false;
                for(int j = m - 1; j >= 0; j--) {
                    if (i + j < n + m - 1 && result[i + j] < 'z') {
                        result[i + j]++; 
                        modified = true;
                        
                        bool violatesT = false;
                        for(int k = 0; k < n; k++) {
                            if(str1[k] == 'T') {
                                for(int l = 0; l < m; l++) {
                                    if(k + l < n + m - 1 && k + l == i + j && result[k + l] != str2[l]) {
                                        violatesT = true;
                                        break;
                                    }
                                }
                            }
                            if (violatesT) break;
                        }
                        
                        if(violatesT) {
                            result[i + j]--; 
                            modified = false;
                        } else {
                            break; 
                        }
                    }
                }
                
                if(!modified) return ""; 
                i = -1; 
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(str1[i] == 'T') {
            bool matches = true;
            for(int j = 0; j < m; j++) {
                if (i + j >= n + m - 1 || result[i + j] != str2[j]) {
                    matches = false;
                    break;
                }
            }
            if(!matches) return "";
        } else {
         
            bool matches = true;
            for(int j = 0; j < m; j++) {
                if(i + j >= n + m - 1 || result[i + j] != str2[j]) {
                    matches = false;
                    break;
                }
            }
            if(matches) return "";
        }
    }
    
    return result;

    }
};



   // string generateString(string str1, string str2) {
    //      int n = str1.length();
    //     int m = str2.length();

    //     auto check = [&](const string& word) {
    //         for (int i = 0; i < n; ++i) {
    //             if (str1[i] == 'T') {
    //                 if (i + m > (int)word.length() || word.substr(i, m) != str2) {
    //                     return false;
    //                 }
    //             } else {
    //                 if (i + m <= (int)word.length() && word.substr(i, m) == str2) {
    //                     return false;
    //                 }
    //             }
    //         }
    //         return true;
    //     };

    //     string smallest = "";
    //     for (int i = 0; i < (1 << (n + m - 1)); ++i) {
    //         string word = "";
    //         for (int j = 0; j < n + m - 1; ++j) {
    //             if ((i >> j) & 1) {
    //                 word += 'b';
    //             } else {
    //                 word += 'a';
    //             }
    //         }

    //         if (check(word)) {
    //             if (smallest == "" || word < smallest) {
    //                 smallest = word;
    //             }
    //         }
    //     }

    //     return smallest;