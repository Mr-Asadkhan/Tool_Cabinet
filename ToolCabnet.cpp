#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class Node {      // Node Class For Queue 
private:
    int Data;
    Node* Next;

public:

    void SetData(int data) {
        Data = data;
    }
    void SetNext(Node* next) {
        Next = next;
    }
    Node* GetNext() {
        return Next;
    }
    int GetData() {
        return Data;
    }
};

 class Heap {
     int array[100];                 // For Max Heap
     int minarray[100];    
 public: 
     
     int size;
     int lenght;                // Will use for Min Heap
    Heap() {
        array[1] = -1;
        minarray[1] = -1;
        size = 0;
        lenght = 0;
    }

 public:
     void insertinMaxHeap(int value) {       //

         size = size + 1;
         int index = size;
         array[index] = value;
         //aa = size;
         while (index > 1)
         {
             int parent = index / 2;
             if (array[parent] < array[index]) {    // Index will indicate child

                 int swap = array[index];            // Here we done swap
                 array[index] = array[parent];
                 array[parent] = swap;
                 index = parent;
             }

             else                          // If parent not less
             {
                 return;
             }
         }
     }
                    // To write data into Max Heap
     void Writedata_intoMax() {
       
         ofstream WriteintoMaxheap;
         WriteintoMaxheap.open("MaxHeapdata.txt", std::ios::app);  //appened base is used to write data without earsing previous data
         for (int i = 1; i <= size; i++) {
             if (WriteintoMaxheap.is_open()) {
                 WriteintoMaxheap << array[i]<<"  ";
                 //cout << endl;
             }
         }
         WriteintoMaxheap << endl;
         WriteintoMaxheap.close();
         cout << "-->Data transfer into file\n";
     }                                  //program writting end here
                    //Read data code start here
     void ReadData_MaxHeap() {
         ifstream readDataMaxHeap("MaxHeapdata.txt");       // Object creating and file opening at same line
         int ck = 0;
         if (readDataMaxHeap.is_open()) 
         {
             string line;
             //getline(readDataMaxHeap, line);                //getline use To get one line From File
            
             // While:  getline return TRUE as Far he get a line ; When he reach into end of file then it will return false
             while (getline(readDataMaxHeap, line)) {
                 cout << line << endl;
                 ck++;
             }
             if (ck == 0) {
                 cout << "-->The File Is Empty\n";
             }
             readDataMaxHeap.close();
         }       
         else 
         {
             cout << "--> Error while file opening\n";
         }

         
     }
    
     void DeleteMax() {
         
         array[1] = array[size];
         size--;
         cout<< "-->Deleted From Max Heap! \n";
         heapiy(1);
  
     }
     void heapiy(int i) {
         int top = i;
         int left = 2 * i;
         int right = 2 * i + 1;

         if (left <= size && array[left] > array[top]) {
             top = left;
         }

	         if (right <= size && array[right] > array[top]) {
             top = right;
         }

         if (i != top) {
             swap(array[top], array[i]);
             heapiy(top);
         }
         

     }
                     //To Search in Max Heap----
     void searchinMaxheap(int key) 
     {
         int nt = 0;
         for (int i = 1; i <= size; i++) {
             if (key == array[i]) {
                 cout << "The Search Element in Max Heap at index \t" << i << endl;
                 nt++;
             }
         }
         if (nt == 0) 
         {         
                 cout << key << "\t Not find in Max_Heap\n";
         }
     }
     
     // To Display MAX HEAP
     void displayMaxheap()
     {
         if (size == 0) { cout << "---No data in Max Heap---\n"; }
         for (int i = 1; i <= size; i++) {
             cout << array[i] << "\t";
         }
         cout << endl;
     }

                                       // MAX HEAP OPERATION ENDS HERE---> BY
    
     // MIN HEAP OPERATION STARTS HERE--->
                                        
     // To INSERT into MIN HEAP 
     void insertin_MinHeap(int value) {
         lenght = lenght + 1;
         int index = lenght;
         minarray[index] = value;

         while (index > 1)
         {
             int parent = index / 2;
             if (minarray[parent] > minarray[index]) {    // Index will indicate child

                 int swap = minarray[index];            // Here we done swap
                 minarray[index] = minarray[parent];
                 minarray[parent] = swap;
                 index = parent;
             }
             else
             {
                 return;
             }

         }

     }
     //To Search in Min Heap----
     void searchinMinheap(int key)
     {
         int nt = 0;
         for (int i = 1; i <= lenght; i++) {
             if (key == minarray[i]) {
                 cout << "The Search Element  in Min Heap at index \t" << i << endl;
                 nt++;
             }
         }
         if (nt == 0)
         {
             cout << key << "\t Not Find in Min_Heap\n";
         }
     }
     // Write  Min Heap Data
     void Writedata_intoMinHeap() {

         ofstream Writeinto_Minheap;    //Object Name

         Writeinto_Minheap.open("MinHeapdata.txt", std::ios::app);  //appened base is used to write data without earsing previous data
         for (int i = 1; i <= lenght; i++) {            //As is 1 so it will write all values
             if (Writeinto_Minheap.is_open()) {
                 Writeinto_Minheap << minarray[i] << "  ";
                 //cout << endl;
             }
         }
         Writeinto_Minheap << endl;
         Writeinto_Minheap.close();
         cout << "-->Data transfer into file\n";
     }                                  //program writting end here
     // Read data from Min Heap file
     void ReadData_MinHeap() {
         ifstream readData_MinHeap("MinHeapdata.txt");       // Object creating and file opening at same line
         int ck = 0;
         if (readData_MinHeap.is_open())
         {
             string line;
             //getline(readData_MinHeap, line);                //getline use To get one line From File

             // While:  getline return TRUE as Far he get a line ; When he reach into end of file then it will return false
             while (getline(readData_MinHeap, line)) {
                 cout << line << endl;
                 ck++;
             }
             if (ck == 0) {
                 cout << "-->The File Is Empty\n";
             }
             readData_MinHeap.close();
         }
         else
         {
             cout << "--> Error while file opening\n";
         }


     }

     void Delete_MinHeap() {

         minarray[1] = minarray[lenght];
         lenght--;
         cout << "-->Deleted Top Element From Min Heap! \n";
         heapiy_Min(1);
         cout << "--->After Deletion Min_Heap\n";
         display_MinHeap();                 //make change

     }

     void heapiy_Min(int i) {
         int top = i;
         int left = 2 * i;
         int right = 2 * i + 1;

         if (left <= lenght && minarray[left] < minarray[top]) {
             top = left;
         }

         if (right <= lenght && minarray[right] < minarray[top]) {
             top = right;
         }

         if (i != top) {
             swap(minarray[top], minarray[i]);
             heapiy_Min(top);
         }


     }
     void display_MinHeap()
    {
        if (lenght == 0) { cout << "---No data in Min Heap---\n";  }
        for (int i = 1; i <= lenght; i++) {
            cout << minarray[i] << "\t";
        }
        cout << endl;
    }

};

class LinkedQueue {
private:
    Node* Front;
    Node* Back;

public:
    

    LinkedQueue() {
        Front = NULL;
        Back = NULL;
    }
    bool IsEmpty() {
        if (Front == NULL) return true;
        else return false;
    }

    void En_Queue(int value) {

        Node* NewNode = new Node();             // object for Node class with name New-Node
        NewNode->SetData(value);
        NewNode->SetNext(NULL);

        if (IsEmpty() == true) Front = Back = NewNode;
        else {
            Back->SetNext(NewNode);
            Back = NewNode;

        }
    }
        
    void writedata_intoQueue(int data) {
        ofstream queue_data("QueueData.txt", std::ios::app);
        if (queue_data.is_open()) {
            queue_data << data;
            queue_data << "\n";
        }
        queue_data.close();
    }
    void D_Queue() {
        if (IsEmpty() == true) cout << " Can't be deleted bcz Queue is Empty\n";
        else {
            Node* temp = Front;
            Front = Front->GetNext();
            cout << "The Top deleted --->" << temp->GetData() << endl;
            delete temp;
            

        }
    }
    void Queue_front() {

        if (IsEmpty() == true) cout << "No Top Element bcz  Queue is Empty\n";

        else {
            cout << "The Top Element of Queue is \t" << Front->GetData();
        }
    }

    void Display_Queue() {
        if (IsEmpty() == true) cout << "The Ak Queue is Empty\n";

        Node* temp;
        temp = Front;
        while (temp != nullptr) {
            cout << temp->GetData() << "->";
            temp = temp->GetNext();
        }cout << endl;


    }
};


int main()
{
    Heap h;                         // Object of heap class IT will Remain in Top
    LinkedQueue ak;                 // Object for Queue

    cout << "--------- Enter 1  To Manipulate With Queue --------- \n";
    cout << "--------- Enter 2  To Manipulate With Heap --------- \n";
    cout << "--------- Enter 3  To Manipulate With BST --------- \n";
    cout << "--------- Enter 0  To Exits From Main and Close Program --------- \n";
    cout << "\t--------------------------------------------------------\n\n";
    int zz = true;
    while (zz)
    {


        cout << "Enter Main_Chocie\n";
        int main_choice;
        cin >> main_choice;


        if (main_choice == 1) {
            //int Queuechoice;
            cout << "\t------- QUEUE OPERATION --------\n\n";
            cout << "Enter 1 For Inserting into Queue\n";
            cout << "Enter 2 To Delete Top Element of Queue\n";
            cout << "Enter 3 to See Top Element of Queue\n";
            cout << "Enter 4  to Dispaly Queue\n";
            cout << "Enter 0  to Exits from Queue\n";
            bool aa = true;
            while (aa)
            {
                int Queuechoice;
                cout << "Enter choice\n";
                cin >> Queuechoice;
                switch (Queuechoice) {

                case 1:
                    //Number to be Entered

                    cout << "How many values U want to Enter into Queue\n";
                    int n;
                    cin >> n;
                    cout << "Enter values for Queue\n";
                    int value;
                    for (int i = 0; i < n; i++) {
                        cin >> value;
                        //cout << endl;
                        ak.En_Queue(value);
                        ak.writedata_intoQueue(value);
                    }
                    cout << "You Entered " << n << " Values \n";

                    break;
                case 2:
                    ak.D_Queue();
                    cout << "Queue After Deletion\n";
                    ak.Display_Queue();
                    break;
                case 3:
                    ak.Queue_front();
                    break;
                case 4:
                    ak.Display_Queue();
                    break;
                case 0:
                    aa = false;
                    cout << "------- You Exits From Queue And Come Back To Main ------- \n";
                    break;
                default:
                    cout << "Please Enter Right Choice \n";

                }

            }
        }

        else if (main_choice == 2) {

            //  Main code For Heap ---->
            int bb = true;
            while (bb)
            {


                int heapchoice;
                cout << "-----Enter 1 for Max heap-----\n";
                cout << "-----Enter 2 for Min heap-----\n";
                cout << "-----Enter 3 to Exits from Heap-----\n";
                cin >> heapchoice;
                cout << endl;


                if (heapchoice == 1)           // Max Heap Operation 
                {
                    cout << "\t------- MAX HEAP OPERATION --------\n\n";                 //15 slash
                    cout << "Enter 1 for Insertion into  Max Heap\n";
                    cout << "Enter 2 for Searching from Max Heap\n";
                    cout << "Enter 3 for Deletion of Top Eelment from Max Heap\n";
                    cout << "Enter 4 To Display Max Heap\n";
                    cout << "Enter 5 To Display Data Max_Heap File\n";
                    cout << "Enter 0 To Out from Max Heap\n";

                    int choiceheap;

                    bool ak = true;
                    while (ak) {
                        cout << "Enter Choice\n";
                        cin >> choiceheap;
                        switch (choiceheap)
                        {
                        case 1:
                            cout << "-----How many values u want to Enter-----\n";
                            int n;
                            cin >> n;                   // show number of values

                            cout << "-----Enter values for Max Heap-----\n";
                            int value;                               // values for Max Heap

                            cout << endl;
                            for (int i = 0; i < n; i++) {
                                cin >> value;
                                h.insertinMaxHeap(value);
                            }
                            cout << n << "  -->Values are entered\n";
                            h.Writedata_intoMax();
                            break;

                        case 2:
                            int key;                        //values that to be Search From Max heap
                            cout << "-----Enter a value that to be Search-----\n";
                            cin >> key;
                            h.searchinMaxheap(key);
                            break;
                        case 3:
                            h.DeleteMax();
                            break;
                        case 4:
                            h.displayMaxheap();
                            break;
                        case 5:
                            h.ReadData_MaxHeap();
                            break;

                        case 0:
                            ak = false;
                            cout << "-----Compiler come out From Max-Heap-----\n\n";
                            break;
                        default:
                            cout << "----- Please Enter Right Choice -----\n";

                        }

                    }
                }

                else if (heapchoice == 2) {

                    cout << "\t------- MIN HEAP OPERATION --------\n\n";                 //15 slash
                    cout << "Enter 1 for Insertion into  Min Heap\n";
                    cout << "Enter 2 for Searching from Min Heap\n";
                    cout << "Enter 3 for Deletion of Top Eelment from Min Heap\n";
                    cout << "Enter 4 To Display Min Heap\n";
                    cout << "Enter 5 To Display Data Min_Heap File\n";
                    cout << "Enter 0 To Out from Min Heap\n";

                    int choice_min;             //For Min Heap

                    bool kk = true;
                    while (kk) {
                        cout << "Enter Choice\n";
                        cin >> choice_min;
                        switch (choice_min)
                        {
                        case 1:
                            cout << "-----How many values u want to Enter-----\n";
                            int n;
                            cin >> n;                   // show number of values

                            cout << "-----Enter values for Min Heap-----\n";
                            int value;                               // values for Max Heap

                            cout << endl;
                            for (int i = 0; i < n; i++) {
                                cin >> value;
                                h.insertin_MinHeap(value);
                            }
                            cout << n << "  -->Values are entered\n";
                            h.Writedata_intoMinHeap();
                            break;

                        case 2:
                            int key;                        //values that to be Search From Max heap
                            cout << "-----Enter a value that to be Search-----\n";
                            cin >> key;
                            h.searchinMinheap(key);
                            break;
                        case 3:
                            h.Delete_MinHeap();
                            break;
                        case 4:
                            h.display_MinHeap();
                            break;
                        case 5:
                            h.ReadData_MinHeap();
                            break;

                        case 0:
                            kk = false;
                            cout << "-----Compiler come out From Min-Heap-----\n\n";
                            break;
                        default:
                            cout << "----- Please Enter Right Choice -----\n";

                        }

                    }
                }
                else if (heapchoice == 3) {
                    cout << " You Exits From Main Heap--> Good Luck!\n\n";
                    bb = false;
                    break;

                }
                else
                {
                    cout << "Please Enter Right Heap_Choice\n";
                }
            }
        }
        // End of Main for Heap--->

        else if (main_choice == 3) {
            cout << "Wait to Done \n";
        }
        else if (main_choice == 0) {
            zz=false;
            cout << "------- The End -------\n";
        }
        else
        {
            cout << "Enter Right Choice Baby \n";
        }



    }
        return 0;


    
}


