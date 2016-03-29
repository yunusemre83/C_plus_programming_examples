
#include <iostream>
#include <cstdlib>
#include <String>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


bool is_unique_str(string in_str){

	int str_len = in_str.length();
	char cur_char;
	bool is_unique = true;
	for (unsigned i = 0; i<str_len - 1; i++)
	{
		cur_char = in_str.at(i);
		for (unsigned j = i + 1; j < str_len ; j++){
			if (cur_char == in_str.at(j)){
				is_unique = false;
				return is_unique;
			}
		}
	}
	return is_unique;
}

bool is_unique_str(char char_arr[]){

	bool is_unique = true;
	char cur_char = char_arr[0];
	char cur_next_char = char_arr[1];
	char next_char = char_arr[1];
	unsigned char_counter = 0;
	unsigned next_char_counter ;
	while (cur_next_char != '\0' ){
		cur_char = char_arr[char_counter];
		next_char_counter = char_counter + 1;
		next_char = char_arr[next_char_counter];
		cur_next_char = next_char;
		while (next_char != '\0' ){
			if (cur_char == next_char){
				is_unique = false;
				return is_unique;
			}
			next_char_counter = next_char_counter + 1;
			next_char = char_arr[next_char_counter];
		}
		char_counter++;
	}
	return is_unique;
}

bool is_unique_str_On(char* char_arr){

	unsigned int char_table[1 << 8] = { 0 };
	unsigned char_counter = 0;
	char cur_char = char_arr[char_counter];


	while (cur_char != '\0'){
		if (char_table[cur_char] != 0){
			return false;
		}
		else{
			char_table[cur_char] = char_table[cur_char]+ 1;
			char_counter++;
			cur_char = char_arr[char_counter];
		}
	}
	return true;

}

void reverse_str(char *char_arr){

	unsigned arr_length = 0;
	char cur_char = char_arr[arr_length];

	while (cur_char != '\0'){
		arr_length++;
		cur_char = char_arr[arr_length];
	}
	char temp_char;
	for (unsigned i = 0; i < (arr_length / 2); i++){
		temp_char = char_arr[i];
		char_arr[i] = char_arr[arr_length - i -1];
		char_arr[arr_length - i -1] = temp_char;
	}
}

void remove_dub_str(char *char_arr){

	unsigned cur_ptr = 0;
	unsigned next_ptr = cur_ptr+1;
	unsigned shift_ptr;

	char cur_char = char_arr[cur_ptr];
	char lookahead_char = char_arr[cur_ptr+1];
	char next_char = char_arr[next_ptr];

	if (cur_char==NULL || cur_char == '\0' || next_char == '\0'){
		return;
	}

	while (lookahead_char != '\0'){
		while (next_char != '\0'){
			if (cur_char == next_char){
				shift_ptr = next_ptr;
				while (char_arr[shift_ptr ] != '\0'){
					char_arr[shift_ptr] = char_arr[shift_ptr+1];
					shift_ptr++;
				}
			}
			next_ptr = next_ptr + 1;
			next_char = char_arr[next_ptr];
		}
		cur_ptr++;
		next_ptr = cur_ptr + 1;
		cur_char = char_arr[cur_ptr];
		lookahead_char = char_arr[cur_ptr + 1];
		next_char = char_arr[next_ptr];
	}
}

void remove_dub_str_On2(char *char_arr){

	unsigned cur_ptr = 1;
	unsigned prev_ptr = 0;
	unsigned accumulated_shift = 0;

	char cur_char = char_arr[cur_ptr];
	char lookahead_char = char_arr[cur_ptr + 1];
	char prev_char = char_arr[prev_ptr];

	bool found_dub = false;
	if (cur_char == NULL || cur_char == '\0' || lookahead_char == '\0'){
		return;
	}

	while (lookahead_char != '\0'){
		while (prev_ptr < (cur_ptr - accumulated_shift)){
			if (cur_char == prev_char){
				accumulated_shift++;
				found_dub = true;
				break;
			}
			prev_ptr = prev_ptr + 1;
			prev_char = char_arr[prev_ptr];
		}
		if (!found_dub){
			char_arr[cur_ptr - accumulated_shift] = char_arr[cur_ptr];
		}
		found_dub = false;
		cur_ptr++;
		prev_ptr = 0;
		cur_char = char_arr[cur_ptr];
		lookahead_char = char_arr[cur_ptr + 1];
		prev_char = char_arr[prev_ptr];
	}

	for (int i = 0; i < accumulated_shift; i++){
		char_arr[cur_ptr - i] = lookahead_char;
	}
}

bool check_anagram_str(char *char_arr_A,char *char_arr_B){

	unsigned int char_table[1 << 8] = { 0 };

	unsigned cur_ptr_A = 0;
	unsigned cur_ptr_B = 0;

	char cur_char_A = char_arr_A[cur_ptr_A];
	char cur_char_B = char_arr_B[cur_ptr_B];

	if (cur_char_A == NULL || cur_char_A == '\0' || cur_char_B == NULL || cur_char_B == '\0'){
		return false;
	}

	while (cur_char_A != '\0'){
		char_table[cur_char_A] = char_table[cur_char_A] + 1;
		cur_ptr_A++;
		cur_char_A = char_arr_A[cur_ptr_A];
	}

	while (cur_char_B != '\0'){
		char_table[cur_char_B] = char_table[cur_char_B] - 1;
		if (char_table[cur_char_B] < 0){
			return false;
		}
		cur_ptr_B++;
		cur_char_B = char_arr_B[cur_ptr_B];
	}

	if (cur_ptr_A != cur_ptr_B){
		return false;
	}

	return true;


}
bool check_reversed_str(char *char_arr_A, char *char_arr_B){

	unsigned cur_ptr_A = 0;
	unsigned cur_ptr_B = 0;

	char cur_char_A = char_arr_A[cur_ptr_A];
	char cur_char_B = char_arr_B[cur_ptr_B];

	if (cur_char_A == NULL || cur_char_A == '\0' || cur_char_B == NULL || cur_char_B == '\0'){
		return false;
	}

	while (cur_char_B != '\0'){
		cur_ptr_B++;
		cur_char_B = char_arr_B[cur_ptr_B];
	}
	cur_ptr_B--;
	while (0 <= cur_ptr_B && cur_char_A != '\0'){

		cur_char_A = char_arr_A[cur_ptr_A];
		cur_char_B = char_arr_B[cur_ptr_B];

		if (cur_char_A != cur_char_B){
			return false;
		}
		cur_ptr_A--;
		cur_ptr_B--;
	}
	if (0 <= cur_ptr_B || cur_char_A != '\0'){
		return false;
	}
	return true;
}

bool palindrome_permutation(char * char_arr){

	unsigned cur_ptr = 0;
	unsigned next_ptr = 0;

	char cur_char = char_arr[cur_ptr];
	char next_char = char_arr[next_ptr];

	bool isodd = false;
	bool firstodd = true;
	while (cur_char != '\0'){
		while (next_char != '\0'){
			if (cur_char == next_char){
				isodd = !isodd;
			}
			next_ptr++;
			next_char = char_arr[next_ptr];
		}
		cur_ptr++;
		cur_char = char_arr[cur_ptr];
		next_ptr = 0;
		next_char = char_arr[next_ptr];
		if (isodd){
			if (firstodd){
				firstodd = false;
				isodd = false;
			}else{
				return false;
			}
		}
	}

	return true;
}

bool palindrome_permutation_On(char * char_arr){

	bool char_table[1<<8] = { false };
	
	unsigned cur_ptr = 0;
	char cur_char = char_arr[cur_ptr];

	unsigned numodd = 0;
	while (cur_char != '\0'){
		char_table[cur_char] = !char_table[cur_char];
		if (char_table[cur_char]){
			numodd++;
		}else{
			numodd--;
		}
		cur_ptr++;
		cur_char = char_arr[cur_ptr];
	}
	if (numodd >= 2){
		return false;
	}
	return true;
}

bool oneway(char * char_arr_A,char * char_arr_B){

	unsigned char_ptr_A = 0;
	unsigned char_ptr_B = 0;

	char char_A = char_arr_A[char_ptr_A];
	char char_B = char_arr_B[char_ptr_B];

	bool is_same = true;
	int scnerio = 0;
	unsigned temp_char_ptr = 0;
	while (char_A != '\0' && char_B != '\0'){

		if (char_A != char_B){
			if (scnerio == 0){
				temp_char_ptr = char_ptr_A;
				char_ptr_A++;
				scnerio++;
			}else if(scnerio == 1){
				char_ptr_A = temp_char_ptr ;
				char_ptr_B = temp_char_ptr;
				char_ptr_B++;
				scnerio++;
			}else if (scnerio == 2){
				char_ptr_A = temp_char_ptr;
				char_ptr_B = temp_char_ptr;
				char_ptr_A++;
				char_ptr_B++;
				scnerio++;
			}else{
				return false;
			}
		}
		char_ptr_A++;
		char_ptr_B++;
		char_A = char_arr_A[char_ptr_A];
		char_B = char_arr_B[char_ptr_B];
	}
	if (scnerio != 0){
		if (char_A != '\0' || char_B != '\0'){
			return false;
		}
	}
	return true;
}


void compression_str(char* char_arr, char* compress_char_arr, unsigned length){

	unsigned cur_ptr = 1;
	unsigned compress_ptr = 0;
	char cur_char = char_arr[cur_ptr];
	char prev_char = char_arr[cur_ptr-1];
	unsigned run_length = 1;
	bool expand = false;
	if (cur_char == '\0' || prev_char=='\0'){
		expand = true;
	}

	char temp_char[10];
	int temp_char_cntr = 0;
	bool last_turn = false;
	while (!last_turn){
		if (cur_char == '\0'){
			last_turn = true;
		}
		if (expand == true){
			break;
		}
		if (prev_char != cur_char){
			compress_char_arr[compress_ptr] = prev_char;
			compress_ptr++;
			if (compress_ptr > length){
				expand = true;
				break;
			}
			while (0 < run_length){
				temp_char[temp_char_cntr] = '0' + run_length % 10;
				run_length = run_length / 10;
				temp_char_cntr++;
			}
			temp_char_cntr--;
			while (0<=temp_char_cntr){
				compress_char_arr[compress_ptr] = temp_char[temp_char_cntr];
				compress_ptr++;
				if (compress_ptr > length){
					expand = true;
					break;
				}
				temp_char_cntr--;
			}
			temp_char_cntr=0;
			run_length = 0;
			prev_char = cur_char;
		}
		if (!last_turn){
			cur_ptr = cur_ptr + 1;
			cur_char = char_arr[cur_ptr];
			run_length++;
		}
	} 

	if (expand){
		compress_char_arr = char_arr;
	}else{
		compress_char_arr[compress_ptr] = '\0';
	}
}



int main(){


	string test_str = "this is a sentence";
	cout << test_str << endl;
	cout << "Characters in the string is unique: " << is_unique_str(test_str) << endl;

	test_str = "this car";
	cout << test_str << endl;
	cout << "Characters in the string is unique: " << is_unique_str(test_str) << endl;

	char char_test[] = "this car";
	cout << char_test << endl;
	cout << "Characters in the string is unique: " << is_unique_str(char_test) << endl;
	cout << "Characters in the string is unique - O(n): " << is_unique_str_On(char_test) << endl;

	char char_test2[] = "this is a sentence";
	cout << char_test2 << endl;
	cout << "Characters in the string is unique: " << is_unique_str(char_test2) << endl;
	cout << "Characters in the string is unique- O(n): " << is_unique_str_On(char_test2) << endl;

	cout << "Dub removed of \'" << char_test2 << "\' is " << endl;
	remove_dub_str_On2(char_test2);
	cout << char_test2 << endl;
	cout << "Characters in the string is unique: " << is_unique_str(char_test2) << endl;

	cout << "Reverse of \'" << char_test2 << "\' is " << endl;
	reverse_str(char_test2);
	cout << char_test2 << endl;

	char char_test3[] = "this is car";
	//char char_test4[] = "isthc  aris";
	char char_test4[] = "isthc  aris";
	cout << "Anagram of str1:\'" << char_test3 << "\' and str2:\'" << char_test4 << "\'is " << check_anagram_str(char_test3, char_test4) << endl;

	char char_test5[] = "tcocaat  ";
	cout << "Permuted Palindrome: " << char_test5 << (palindrome_permutation(char_test5) ? " True" : " False") << endl;
	cout << "Permuted Palindrome On: " << char_test5 << (palindrome_permutation_On(char_test5) ? " True" : " False") << endl;

	char char_test6[] = "pale";
	char char_test7[] = "bae";
	cout << "Are these one edit close: " << char_test6 <<  " " << char_test7 << " :" << (oneway(char_test6,char_test7) ? " True" : " False") << endl;

	char char_test8[] = "baaaaaaaaaaaaaaaaddds aeeee";
	char char_test9[] = "baaaaddds aeeee";
	cout << "Compressing: " << char_test8 << " into ";
	compression_str(char_test8,char_test9,17);
	cout << char_test9 << endl;

	system("pause");
}