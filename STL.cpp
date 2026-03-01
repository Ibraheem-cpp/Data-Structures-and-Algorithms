#include<bits/stdc++.h>
using namespace std;

void pairs_practice(){

    pair<string , pair<string , pair<char, int >>> p;
    cin >> p.first;
    cin >> p.second.first;
    cin >> p.second.second.first;
    cin >> p.second.second.second;

    cout << p.first << " " << p.second.first << " ";
    cout << p.second.second.first << " " << p.second.second.second << endl;

        pair<int,int> p1[3] = {{2,3},{4,5},{6,7}};
        swap(p1[0].first,p1[2].second);
        for(int i=0;i<3;i++){
            cout << p1[i].first << " " << p1[i].second << endl;
        }
}

void vectors_practice(){

    //  arrays that can grow and shrink in size

    vector<int> v(5);
    v[1] = 9;
    v.push_back(56);
    vector<pair<int,int>> v2(5,{2,3});

    vector<pair<int,int>>::iterator it2 = v2.begin();

    for(auto it = v.begin() ; it != v.end() ; it++){
        cout << *(it) << " ";
    }
    cout << endl;

    for(auto it : v){
        cout << it << " ";
    }

    cout << endl;

    for(auto it_2 = v2.begin() ; it_2 != v2.end() ; it_2++){
        cout << it_2->first << " " << it_2->second << endl;
    }

    cout << endl;

    for(const auto &it3 : v2){
        cout << it3.first << " " << it3.second << endl;
    }

    cout << endl;

    vector<int> v3(5);
    v3[0] = 10,v3[1] = 20, v3[2] = 30, v3[3] = 40, v3[4] = 50;
    v3.erase(v3.begin()+2,v3.end());

    v3.insert(v3.end(),v.begin(),v.end()); // -> basically this is copying
    v3.clear();
    for(const auto &i : v3){
        cout << i << " ";
    }
    cout << endl;
    cout << v3.empty();

    
}

void lists_practice(){

    // can add and erase elements at the front

    list<int> l1(4,5);
    list<int> l2(5,6);
    l1.push_front(6);
    l1.insert(l1.end(),59);
    l1.swap(l2);
    l1.pop_front();
    l1.push_front(17);
    l1.sort();
    for(auto i = l1.begin() ; i != l1.end() ; i++){
        cout << *i << " ";
    }

    cout << endl;
}

void stack_practice(){

    // LIFO -> Last in First Out
    stack<int> s1;
    s1.push(5);s1.push(6);s1.push(7);
    
    stack<int> s2 = s1;
    s2.pop();
    s1.swap(s2);
    cout << s2.top() << endl;
    
    stack<pair<int,int>> s3;
    s3.push({3,4});
    cout << s3.size() << endl;
    cout << s3.top().first << " " << s3.top().second;

}

void queue_practice(){

    // FIFO -> First in First Out

    queue<int> q1;
    q1.push(5);
    q1.emplace(10);
    q1.front() += 5;
    q1.back() += 6;
    cout << q1.front() << " " << q1.back() << endl;

    //     PRIORITY QUEUE

    // MAX HEAP -> largest element is at the top
    priority_queue<int> pq1;
    pq1.push(10);
    pq1.emplace(5);
    pq1.push(8);
    pq1.pop();
    cout << pq1.top() << endl;

    // MIN HEAP -> Smallest element is at the top
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.emplace(5);
    pq2.push(10);
    cout << pq2.top() << endl;

}

void set_practice(){

    // stores unique elements in sorted order

    set<int> s1;
    s1.insert(5);    // -> TC = n log n
    s1.emplace(4);s1.insert(3);s1.insert(8);
    s1.insert(10);

    for(auto it = s1.begin() ; it != s1.end() ; it++){
        cout << *it << " ";
    }

    cout << endl;
    auto it1 = s1.begin();
    auto it2 = s1.find(5);
    s1.erase(it1,it2);

    for(auto it : s1){
        cout << it << " ";
    }

    auto it4 = s1.upper_bound(5);
    cout << endl << *it4 << endl << endl;


    //       MULTI-SET
    // stores elements in sorted order but not unique

    multiset<int> ms;
    ms.insert(1);ms.insert(1);ms.insert(1);ms.insert(5);
    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;
    ms.erase(1); // --> erases all occurences of 1
    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;
    ms.insert(1);ms.insert(1);ms.insert(1);
    for(auto it = ms.begin() ; it != ms.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;

    auto it5 = ms.find(1);
    ms.erase(it5); // --> erases only the first 1 because iterator points to the first occurence of 1
    for(auto it = ms.begin() ; it != ms.end() ; it++){
        cout << *it << " ";
    }
    cout << endl << endl;


    //       UNORDERED-SET
    // stores unique elements but not in sorted order
    // lower bound and upper bound functions do not work

    unordered_set<int> us1;
    us1.insert(5);us1.insert(5);us1.insert(7);us1.insert(2);

    for(auto it = us1.begin() ; it != us1.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;

}

void map_practice(){

    // unique keys stored in sorted order
    // each key is binded to another value
    // two values cannot have same value

    map<int,string> m1;
    m1.insert({241,"Ibraheem"});
    m1.insert({236,"Umer"});
    m1.insert({919,"Waqar"});
    m1.insert({40,"Huzaifa"});

    auto it1 = m1.find(40);
    
    for(auto it : m1){
        cout << it.first << " " << it.second << endl;
    }

    auto it2 = m1.lower_bound(39);
    cout << (*it2).second << endl;

    auto it3 = m1.upper_bound(241);
    cout << (*it3).second << endl;


    //   MULTI-MAP
    // same as map but can store multiple same keys in sorted order
    // cannot access map[key] directly


    //  UNORDERED-MAP
    // stores keys in unsorted order but still each key is unique
}


int main(){

    map_practice();

    return 0;
}

