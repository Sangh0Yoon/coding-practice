#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct seat_info{
	int id;
	int seat_number;
	int distance;
};

list<seat_info> SeatInfo;
vector<seat_info> result;
int n, k;

void seating(int ID);
bool check_Already_Seating(int ID);
void leave_seat(int ID);

int main(){
	cin >> n >> k;
	for(int i=0;i<k;i++){
		int ID; cin >> ID;
		if(check_Already_Seating(ID)){
			leave_seat(ID);
		}
		else{
			seating(ID);
		}
	}

	for(auto out : result){
		cout << out.id << " " << out.seat_number << endl;
	}
}

void seating(int ID){
	list<seat_info>::iterator it;
	seat_info new_seat = {ID,0,0};
	
	if(SeatInfo.empty()){	
		it		 = SeatInfo.begin();
		new_seat = {ID,1,n-1};
	}
	else{
		int max_dist = 0;
		
		for(auto i=SeatInfo.begin(); i!=SeatInfo.end(); i++){
			if(i->distance > max_dist){
				max_dist 	= i->distance;
				it 			= i;
			}
		}
		
		it->distance = (max_dist%2==0) ? (max_dist/2-1) : (max_dist/2);
		
		int gap    = (max_dist/2);
		int number = (it->seat_number + it->distance)%n + 1;
		
		new_seat = {ID, number, gap};
	}

	if((it->seat_number + it->distance) / n >= 1) {
		SeatInfo.insert(SeatInfo.begin(),new_seat);
		result.push_back(new_seat);
	}
	else{
		it++;
		SeatInfo.insert(it,new_seat);
		result.push_back(new_seat);
	}
}

bool check_Already_Seating(int ID){
	bool ret_val = false;
	for(auto k : SeatInfo){
		if(k.id == ID) {
			ret_val = true;
			break;
		}
	}
	return ret_val;
}

void leave_seat(int ID){
	list<seat_info>::iterator it;
	
	for(auto i=SeatInfo.begin(); i!=SeatInfo.end(); i++){
		if(i->id == ID){
			it=i;
			break;
		}
	}
	
	int dist = it->distance;

	if(it == SeatInfo.begin()){
		list<seat_info>::iterator last_it = --SeatInfo.end();
		last_it->distance = last_it->distance + dist + 1;
		SeatInfo.erase(it);
	}
	else{
		it--;
		it->distance = it->distance + dist + 1;
		it++;
		SeatInfo.erase(it);
	}
}