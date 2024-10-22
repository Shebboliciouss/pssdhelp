//Received 100/100

#ifndef BRIDGESORT_HPP
#define BRIDGESORT_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class BridgeSort {

	public:
		string sortedHand(string hand) {
			vector<string> vec;
			for(int i=0; i<hand.size(); i++) {
				if(hand[i] == 'T') {
					hand[i] = 'U';
				}
				if(hand[i] == 'J') {
					hand[i] = 'V';
				}
				if(hand[i] == 'Q') {
					hand[i] = 'W';
				}
				if(hand[i] == 'K') {
					hand[i] = 'X';
				}
				if(hand[i] == 'A') {
					hand[i] = 'Y';
				}
				if(i % 2 != 0) {
					string temp = "";
					temp = temp + hand[i-1];
					string temp1 = "";
					temp1 = temp1 + hand[i];
					vec.push_back(temp+temp1);
					temp = "";
					temp1 = "";
				}
			}
			sort(vec.begin(),vec.end());
			string new_hand = "";
			for(int j=0; j<vec.size(); j++) {
				if(vec[j][1] == 'U') {
					vec[j][1] = 'T';
				}
				if(vec[j][1] == 'V') {
					vec[j][1] = 'J';
				}
				if(vec[j][1] == 'W') {
					vec[j][1] = 'Q';
				}
				if(vec[j][1] == 'X') {
					vec[j][1] = 'K';
				}
				if(vec[j][1] == 'Y') {
					vec[j][1] = 'A';
				}
				new_hand = new_hand + vec[j];
 			}
			return new_hand;
		}

};

#endif