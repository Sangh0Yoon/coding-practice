#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct People{
    int id;
    int age;
    char jender;
};

vector<People> old;
vector<People> child;
vector<People> adult;

void assign_group_by_age(People new_people);
void ordering_old();
void ordering_adult();
bool compare_old(People& a, People& b);
bool compare_adult(People& a, People& b);
void print_old();
void print_child();
void print_adult();

int main(){
    int N; cin >> N;
    People new_people = {0,0,'\0'};
    for(int i=0;i<N;i++){
        int id, age; char jender;
        cin >> id >> age >> jender;
        new_people = {id,age,jender};
        assign_group_by_age(new_people);
    }
    ordering_old();
    ordering_adult();

    print_old();
    print_child();
    print_adult();
}

void assign_group_by_age(People new_people){
    if(new_people.age <= 15){
        child.push_back(new_people);
    }
    else if(new_people.age >= 16 && new_people.age <=60){
        adult.push_back(new_people);
    }
    else{
        old.push_back(new_people);
    }
}

bool compare_old(People& a, People& b){
    return a.jender > b.jender;
}
bool compare_adult(People& a, People& b){
    return a.jender < b.jender;
}

void ordering_old(){
    sort(old.begin(),old.end(),compare_old);
}
void ordering_adult(){
    sort(adult.begin(),adult.end(),compare_adult);
}
void print_old(){
    for(auto k : old) {cout << k.id << endl;}
}
void print_child(){
    for(auto k : child) {cout << k.id << endl;}
}
void print_adult(){
    for(auto k : adult) {cout << k.id << endl;}
}