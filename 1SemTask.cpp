#include <iostream>
#include <algorithm>
#include <vector>

class StaticMap{
public:
    StaticMap(std::vector<std::pair<int, int>> a){
        sort(a.begin(), a.end());
        vector = a;
        size = a.size();
    };

int Get(int key, int def){
    int left = 0, right = size - 1;
    while(true){
        if(right == left){
            if(vector[ left].first == key) return(vector[ left].second);
            break;
        }
        if(vector[(left+right)/2].first == key){
            return(vector[(left+right)/2].second);
        }
        if(vector[(left+right)/2].first > key){
            right = (left+right)/2 - 1;
        }
        if(vector[(left+right)/2].first < key){
            left = (left+right)/2 + 1;
        }
    }
    return(def);
};

bool FindKey(int key){
    int left = 0, right = size - 1;
    bool is_found = false;
    while(!is_found){
        if(right - left <= 1){
            if(vector[ left].first == key || vector[right].first == key){
                is_found = true;
                continue;
            }
            return(false);
        }
        if(vector[(left+right)/2].first == key){
            is_found = true;
            continue;
        }
        if(vector[(left+right)/2].first > key){
            right = (left+right)/2;
        }

        if(vector[(left+right)/2].first < key){
            left = (left+right)/2;
        }
    }
    return(true);
};

private:
    std::vector<std::pair<int, int>> vector;
    int size;
};


int main(){
    // Тестируем на произвольном неотсортированном векторе
    StaticMap A({{5, 50},{1, 10},{3, 30},{9,900},{31, 310},{8,80000},{6,60},{13,130},{20,200},{4,40},{17,170}});
    std::cout << A.Get(11, 1000) << std::endl;
    std::cout << A.FindKey(51) << std::endl;
    std::cout << A.Get(3, 1000) << std::endl;
    std::cout << A.FindKey(17) << std::endl;
}
