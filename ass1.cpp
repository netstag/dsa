 #include <iostream>
using namespace std;

struct student{

string name;
int rollno;
double sgpa;
};

void bubblesort( student arr[],int n){
	for(int i=0; i<n-1; i++){
	for(int j=0; j<n-i-1; j++){
	if(arr[j].rollno>arr[j+1].rollno){

	swap(arr[j].rollno , arr[j+1].rollno);

	}
	}
	}
	
	cout<<"1) The Roll wise arrangemnt is"<<endl;
  cout<<endl;
	for(int k=0; k<n; k++ ){
	cout<<"Rollno "<<arr[k].rollno<<"\t Name-: "<<arr[k].name<<"\t SGPA-: "<<arr[k].sgpa<<endl;
	
	}

}//bubble sort end




 void insertionsort(student arr[],int n){
    //for unsorted array
    for(int i=0; i<n-1; i++){

        string curr = arr[i].name;
        int prev = i-1;

        while(prev>=0 && arr[prev].name>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1].name=curr;

    }
cout<< endl;
cout<< endl;

cout<< "2) Alphabetecial order of the students is:"<<endl;
cout<<endl;
    for(int i=0; i<n; i++){
        cout<<"name-:"<<arr[i].name<<" \t"<<"Rollno-:"<<arr[i].rollno<<"\t  "<<"SGPA-:"<<arr[i].sgpa<<endl;
    }
    

}


//searching sgpa
void linears(student arr[], int n) { 
cout<<endl;
cout<<endl;

cout<<"3) Enter the sgpa-:\t";


double ksgpa;
cin>>ksgpa;
  for(int i=0; i<n; i++) {
  if(ksgpa == arr[i].sgpa ){
    cout<<"the names of the student having same SGPA are-:\n";
  cout<<"Name-:"<<arr[i].name<<" \t "<<"Rollno.-:"<<arr[i].rollno<<"  \t "<<"SGPA:-:"<<arr[i].sgpa<<endl;
  cout<<endl;
  	}
}
 
}

//binary sreach
int binarySearch(student arr[], int st, int end) {
  cout<<endl;
  cout<<endl;
cout<<"4) Enter the Name:";

string name;
cin>>name;
	
  while (st <= end) {
    int mid = st + (end - st) / 2;

    if (name == arr[mid].name){
      cout<<"5) The Detail of the student is-; \n";
    cout<<"name-:\t"<<arr[mid].name<< "\t Rollno-:"<<arr[mid].rollno<<"\tSGPA-: \t"<<arr[mid].sgpa<<endl; 
    cout<<endl;

    break;
    }

    else if (arr[mid].name < name){
      st = mid + 1;
}
    else{
      end = mid - 1;}
  }

  return -1;
}


//QUICKSORT
void printarr(student arr[], int n){
    cout<<"6)toppers wise list of the student is-:";
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<"sgpa-: "<<arr[i].sgpa<<"\t name-: "<<arr[i].name<<"\t rollno-: "<<arr[i].rollno<<endl;
        cout<<endl;
    }
  }


 int partition(student arr[],int si,int ei){
        int i= si-1;
        float pivot = arr[ei].sgpa;
        for(int j=si; j<ei; j++){
            if(arr[j].sgpa <= pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
            i++;
            swap(arr[i],arr[ei]);
           
        
        //pivotIdx = i;
         return i;
  }
   void  quicksort(student arr[],int si,int ei){
    if(si>=ei){
        return;
    }

    int pivotIdx = partition(arr,si,ei);

    quicksort(arr,si,pivotIdx-1); //left half
     quicksort(arr,pivotIdx+1,ei); //right half

  }



int main() {
student arr[] = {
 {"kaustubh" , 45 , 8.45},
 {"prajwal" , 48 , 7.55},
 {"damodar" , 37 , 6.65},
 {"dheeraj" , 27 , 8.41},
 {"mangesh" , 36 , 9.61},
 {"virat" , 17 , 9.45},
 {"rohit" , 46 , 8.45},
 {"lokesh" , 10 , 5.69},
 {"amir" , 41 , 8.55},
 {"salman" , 82 , 4.26},
 {"shahruk" , 56 , 9.39},
 {"neeraj" , 71 , 4.45},
 {"messi" , 85 , 8.44},
 {"rolando" , 69 , 9.45},
 {"neymar" , 70 , 9.41}
};
bubblesort(arr,15);
insertionsort(arr,15);
linears(arr,15);
binarySearch(arr,0,14);
quicksort(arr,0,14);
printarr(arr,15);

return 0;
} 