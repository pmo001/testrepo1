#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

/// Basic implementation for bubble sort with two nested loops.
/// The outer loop defines the range that is not yet sorted and the inner loop
/// passes over the unsorted range and swaps every unordered pair
/// You do not have to use the optimization heuristics that we described in class
/// but you can implement them if you would like.
template <typename T>
void bubbleSort(vector<T>& a) {
  // TODO
  
  int intHolder = 0;
  
  for (int i = 0; i < a.size() - 1; ++i)
  {
  	for (int j = i + 1; j < a.size(); ++j) //(i + 1) b/c want to be after the i 
  	{
  		if (a.at(i) > a.at(j))
  		{
  			intHolder = a.at(i);
  			a.at(i) = a.at(j);
  			a.at(j) = intHolder;
  		}
  		
  		else if (i == a.size() - 2) //want to stop before the j
  		{
  			break;
  		}
  	}
  }
}

// In insertion sort, we start with an array of one element and then we keep
// expanding this array element-by-element while ensuring the array is sorted
// after adding each element

template <typename T>
void insertionSort(vector<T>& a) {
	//third method
	
	int hole, currVal;
	for (int i = 1; i < a.size(); ++i) //a sole element is already sorted, so can go to next
	{
		currVal = a.at(i);
		hole = i;              
		
		while (hole > 0 && a.at(hole - 1) > currVal)
		{
			a.at(hole) = a.at(hole - 1);
			hole = hole - 1;
		}
		
		a.at(hole) = currVal;
		
	}
}
	
  
/*    //second attempt
  
  vector<T> tmpV;
  
  if (!a.empty()) //checks if a is empty or not
  {
  	tmpV.push_back(a.at(0));
  	
  	cout << "cas1: index 0: " << tmpV.at(0) << endl;
  	
  	for (int i = 1; i < a.size(); ++i)
  	{
  		if (a.at(i) < tmpV.at(0))
  		{
  			tmpV.insert( tmpV.begin(), a.at(i) );
  			
  			cout << "cas2: inserting at the beginning" << endl;
  			
  		}
  		
  		else if (a.at(i) > tmpV.at( tmpV.size() - 1) )
  		{
  			tmpV.push_back(a.at(i));
  			
  			cout << "cas3: inserting at the back" << endl;
  		}
  		
  		for (int j = 0; j < tmpV.size() - 1; j++, cout << "dont know y this part keeps looping" << endl)
  		{
  			
  			if (a.at(i) > tmpV.at(j) && a.at(i) < tmpV.at(j + 1))
  			{
  				tmpV.insert(tmpV.begin() + j + 1, a.at(i));
  				
  				cout << "cas4: inserting in between" << endl;
  			}
  		}
  	}
  	cout << "cas5: printing out a: ";
  	
  	for (int z = 0; z < tmpV.size(); ++z)
  	{
  		a.at(z) = tmpV.at(z);
  		
  		cout << a.at(z) << " ";
  	}
  }
}
*/  	
  	/*
  	//need two elements in tmpV first, or else it will loop forever (the inner loop: j=0, j<1)
		tmpV.push_back(a.at(0)); 
		
		if (a.at(1) > tmpV.at(0))
		{
			tmpV.push_back(a.at(1));
		}
		else
		{
			tmpV.insert(tmpV.begin() + 0, a.at(1));
		}
  
  
	  cout << ">>>>>>>>>>>>point1<<<<<<<<<<<<<" << endl;
	  
	  for (int i = 2; i < a.size(); ++i)
	  {
	  	//tmpVinsertPos = i;
	  	//tmpV.push_back(a.at(i)); 
	  	
	  	cout << ">>>>>>>>>point2<<<<<<<<<<<<<" << endl;
	  	
	  	for (int j = 0; j < tmpV.size(); ++j)
	  	{
	  		if (a.at(i) <= tmpV.at(0))
	  		{
	  			tmpV.insert(tmpV.begin() + 0, a.at(i)); //IMPORTANT have the tmp.begin() to work
	  			                                        //first it. inserts 3 at 5's pos
	  			cout << "point3: inserts at beginning" << endl;
	  		}
	  		
	  		// // this case already taken care of 
	  		// else if (a.at(i) >= tmpV.at(0))
	  		// {
	  		// 	tmpV.push_back(a.at(i)); //takes care of the base case when only one element in tmpV
	  			
	  		// 	cout << "point4: base case of 1 element in tmpV" << endl;
	  		// }
	  		
	  		
	  		
	  		else if (a.at(i) >= tmpV.at(j) && a.at(i) <= tmpV.at(j + 1) && (j + 1) < tmpV.size())
	  		{ //inserts between two numbers and makes sure the right number doesn't go past size
	  			tmpV.insert(tmpV.begin() + j + 1, a.at(i)); //inserts after j
	  			
	  			
	  			cout << "point5: inserts between two elements" << endl;
	  		}
	  		
	  		
	  		else if (a.at(i) >= tmpV.at(tmpV.size() - 1))
	  		{ //inserts after the last element if bigger than last element in tmpV
	  			tmpV.push_back(a.at(i));
	  			
	  			cout << "point6: inserts at end" << endl;
	  		}
	  	}
	  }
	  
	  
	  cout << "point7: assigning tmpV to a" << endl;
	  
	  //assign tmpV to a
	  a = tmpV;
  }
*/



/// Selection sort makes n-1 passes over the array where in iteration i it selects
/// the i-th smallest element and places it in its correct position in the array.
template <typename T>
void selectionSort(vector<T>& a) {
	// TODO
	
	int minVal = a.at(0);
	int minValpos = 0;
	
	for (int j = 0; j < a.size(); ++j)
	{
		for (int i = j; i < a.size(); ++i)
		{
			if (minVal > a.at(i))
			{
				minVal = a.at(i);
				minValpos = i;
			}
		}
		
		a.insert(a.begin() + j, minVal); //after insert, there will be two copies of
			                                 //the same num, so have to delete first one
		a.erase(a.begin() + minValpos + 1);  //IMP: MUST HAVE BEGIN() or will fail
	}
	
}

/// Implement the original Shell sort algorithm which uses gaps of sizes
/// n/2, n/4, ..., 1
template <typename T>
void shellSort1(vector<T>& a) {
	// TODO
	
	int tmpVal;
	int n = a.size();
	
	//i > 0 makes sure gaps are 1 or greater
	for (int i = n/2; i > 0; i = i/2) //the gaps get smaller until hits 1
	{
		for (int j = i; j < n; ++j)
		{
			for (int k = j - i; k >= 0; k = k - i)
			{
				if (a.at(k + i) >= a.at(k)) //if higher index->val is greater, break
				{
					break;
				}
				else //else switch values
				{
					tmpVal = a.at(k);
					a.at(k) = a.at(k + i);
					a.at(k + i) = tmpVal;
				}
			}
		}
	}
}

//template <typename T> //don't need?
int medianOf3(int x, int y, int z)
{
	if ( (x <= y && x >= z) 
	  || (x >= y && x <= z) )
	{
		//cout << endl << "median of 3: " << x << " " << y << " " << z << endl;
		return x;
	}
	
	else
	{
		medianOf3(z, x, y);
	}
}

template <typename T>
int Partition(vector<T>& a, int start, int end)
{
	int partitionIndex = 0; //the elements to the left of partition are lesser than pivot
	int pivotIdx = 0;
	int tmpVal = 0;
	
	
	int x = a.at(start);         //since working with only one vector, cannot do 0, size()/2, size()-1 
	int y = a.at(end/2);
	int z = a.at(end);
	
	
	int pivot = medianOf3(x, y, z); //most likely works even with only two elements in sublist
	                                //to account for this, in medianOf3, make the comparisons >=, <=
	
	/*                                
	cout << "printing out sublists: ";
	for (int j = start; j <= end; ++j)
	{
		cout << a.at(j) << " ";
	}
	cout << endl;
	*/
	
	//remembers pivot index but we want to return partitionIndex, not this
	if (pivot == x)
	{
		pivotIdx = start; //since working with only one vector, cannot do 0, size()/2, size()-1 
	}
	else if (pivot == y)
	{
		pivotIdx = end/2;
	}
	else
	{
		pivotIdx = end;
	}
	
	//moving pivot to end of sublist (IMPORTANT: since working with only one vector,...
	                                 //...cannot push_back, must stick it at end of sublist)
	a.insert(a.begin() + end + 1, a.at(pivotIdx) );
	a.erase(a.begin() + pivotIdx); //since duplicated, delete old one
	//keep forgetting needs begin()
	
	////////////////////////
	
	partitionIndex = start; //separates lesser-than-pivot vals from unsorted
	
	for (int i = start; i < end; ++i) //i stops before pivot--where end is where pivot is curr located
	{
		if (a.at(i) <= pivot) //if lesser than pivot, swap with partition
		{
			tmpVal = a.at(i);
			a.at(i) = a.at(partitionIndex);
			a.at(partitionIndex) = tmpVal;
			
			++partitionIndex; //if swap occurs, incre partition, leaving lesser left vals untouched
		}
	}
	
	//after lesser-than-pivot vals are in place, swap pivot with partitionIndex to put pivot in rightful place
	tmpVal = a.at(partitionIndex); 
	a.at(partitionIndex) = a.at(end); //IMPORTANT: since working with only one vector...
	a.at(end) = tmpVal;
	
	return partitionIndex; //since pivot has become the partition, it returns pivot index
	
}

template <typename T>
void quickSort(vector<T>& a, int start, int end) //uses one array; start and end indexes mark boundary of sublists
{
	int pivotIndex = 0;
	
	//'>' accounts for sublist of 2 with no element to right of pivot ["null",pivot, 3]
	if (start >= end) //prob would be alright to just say (start == end) since I always push pivot to back
	{
		return;
	}
	
	pivotIndex = Partition(a, start, end); //returns index of pivot after it is swapped back to rightful pos
	                                       //specifically, it needs to be between lesser left and greater right
	
	quickSort(a, start, pivotIndex - 1); //recur sorts left of pivot
	quickSort(a, pivotIndex + 1, end);   //recur sorts right of pivot
	
}

/// Use Hibbard's increments for the gaps which are in the form of 2^k-1
/// Find more details on page 298 of the book
template <typename T>
void shellSort2(vector<T>& a) {
	// TODO (Optional 10% bonus)
	
	
}

/// Check whether an array is sorted or not
template <typename T>
bool isSorted(vector<T> a) {
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] > a[i+1]) {
			cout << "Elements a[" << i << "]= "<< a[i] << " and a["<<(i+1)<<"] = " << a[i+1] << " are out of order" << endl;
		  return false;
		}
	}
	return true;
}

int main() {
	// Simple test for sorting algorithms
	vector<int> values = {10, 3, 5, 7, 2, 1, 15, 13};
	vector<int> temp = values;
	
	bubbleSort(temp);
	//cout << ">>> Sorting using bubblesort <<<    ";
	EXPECT_TRUE(isSorted(temp));
	//cout << endl << "End of bubblesort" << endl;
	
	temp = values;
	cout << ">>>>> Sorting using quickSort <<<<<<         ";
	quickSort(temp, 0, temp.size() - 1); //arguments are begin and end indexes of temp
	EXPECT_TRUE(isSorted(temp));
	cout << endl << "End of quickSort" << endl;
	
	
	temp = values;
	//cout << ">>> Sorting using insertionSort <<<    ";
	insertionSort(temp);
	EXPECT_TRUE(isSorted(temp));
	//cout << endl << "End of insertionSort" << endl;
	

	temp = values;
	//cout << ">>>beginning of selectionSort<<<<";
	selectionSort(temp);
	EXPECT_TRUE(isSorted(temp));
	//cout << endl << "End of selectionsort" << endl;

	temp = values;
	//cout << ">>>beginning of shellSort1<<<<";
	shellSort1(temp);
	EXPECT_TRUE(isSorted(temp));
	//cout << endl << "End of shellSort1" << endl;
	
	
	// Measure the running time as the input size increases
	cout << right << setw(16)  << "Size"
	     << setw(16)  << "Bubble"
	     << setw(16)  << "Insertion"
	     << setw(16)  << "Selection"
	     << setw(16)  << "Shell 1"
	     << setw(16)  << "Quick"
	     << setw(16)  << "Shell 2" << endl;

	for (int n = 1; n <= (1<<16); n *= 2) {
		cout << setw(16) << right << n;
		values.clear();
		for (int i = 0; i < n; i++)
			values.push_back(random());
		temp = values;
		clock_t begin = clock(); // Start the stopwatch
		bubbleSort(temp);
		clock_t end = clock(); // Stop the stopwatch
    double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;

		temp = values;
		begin = clock();
		insertionSort(temp); 
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;

		temp = values;
		begin = clock();
		selectionSort(temp);
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;

		temp = values;
		begin = clock();
		shellSort1(temp);
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;
    
    	temp = values;
		begin = clock();
		quickSort(temp, 0, temp.size() - 1); 
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;

		temp = values;
		begin = clock();
		shellSort2(temp);
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;
    
    cout << endl;
	}
	
	
	
	return 0;
}
