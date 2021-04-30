#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const unsigned MAX = 10;


string convert_string(string s){ /* CONVERT TO UPPER CASE STRING */
    string s1 = "";                   /** This function is mainly used to compare strings. **/
    for(int i=0;i<s.length();i++)
        s1 += toupper((1, s[i]));
    return s1;
}

/** ## START OF POINTER IMPLEMENTATION ##**/
typedef struct Node{
    string name;
    Node* next_name;
}Node;
typedef Node* pNode;
pNode myList2;

void init_pointer(pNode &p){ /** INIT OUR LIST **/
    p = 0;
}

void forward_pointer(pNode p){ /** FORWARD TRAVERSE OUR LIST **/
    pNode temp = p;
    while(temp !=0){
        cout << temp->name << ", ";
        temp = temp->next_name;
    }
}

void backward_pointer(pNode p){ /** BACKWARD TRAVERSE OUR LIST **/
    pNode temp = p;
    if(temp!=0){
        backward_pointer(temp->next_name);
        cout << temp->name << ", ";
    }
}

int search_pointer(pNode &p,string name){
    if(p==0)
        cout << "List is empty" << endl;
    else {
        pNode temp = p;
        int position=1;
        while( temp!=0 && (convert_string(name) != convert_string(temp->name)) ) {
            position++;
        }

        /** if we did find it before the end of the list **/
        if(temp!=0)
            return position;
    }
    /** we didn't find it **/
    return -1;

}

void delete_pointer(pNode &p,string name){
    if(p==0){
        cout << "List is empty nothing to delete!";
    /** We need to search for the name on the list **/
    } else {
        /** loop over the list until we find our name **/
        pNode temp = p, temp1 = 0;
        while( temp!=0 && (convert_string(name) != convert_string(temp->name))){
            temp1 = temp;
            temp=temp->next_name;
        }

        /** case 1: we reached the end of the list without finding the name **/
        if(temp==0)
            cout << "Could not find such name on the list.";
        /** case 2: we found the name **/
        else {
            /** case 1: we are at the beginning of the list **/
            if(temp1==0){
                temp = temp->next_name;
                p = temp;

            /** case 2: this case treats both in the middle and at the end of the list **/
            } else
                temp1->next_name=temp->next_name;

            /** delete temp **/
            temp = 0;
        }
    }
}


void delete_pointer(pNode &p, unsigned position){
    if(p==0){
        cout << "List is empty nothing to delete!";
    /** We need to search for the name on the list **/
    } else {
        /** loop over the list until we find our name **/
        pNode temp = p, temp1 = 0;
        int index=1;
        while( temp!=0 && index<position){
            temp1 = temp;
            temp=temp->next_name;
            index ++;
        }
        /** case 1: we reached the end of the list without finding the name **/
        if(temp==0)
            cout << "Could not find such name on the list.";
        /** case 2: we found the name **/
        else {
            /** case 1: we are at the beginning of the list **/
            if(temp1==0){
                temp = temp->next_name;
                p = temp;

            /** case 2: this case treats both in the middle and at the end of the list **/
            } else
                temp1->next_name=temp->next_name;

            /** delete temp **/
            temp = 0;
        }
    }
}

void insert_pointer(pNode &p,string name){
    /** Step 1: if my list is empty. **/
    if(p==0){
        p= new Node;
        p->name=name;
        p->next_name=0;
    } else {

        /** Step 2: list not empty **/
        /** Step 2.1.0: create variables **/
        pNode temp1 = 0, temp = p;

        /** Step 2.1: loop until we reach the proper position for our name **/
        while( temp!=0 && convert_string(name) > convert_string(temp->name)){
            temp1 = temp; /** save previous temp **/
            temp=temp->next_name; /** increment to the next temp **/
        }

        /** Step 2.2: insertion of our name **/
        /** Step 2.2.0: create a variable **/
        pNode desiredNode = new Node;
        desiredNode->name=name;
        desiredNode->next_name=temp; /** this works since temp would equal null
                                        if we arrived to end of list and equal
                                        to p if we found a position **/

        /** Step 2.2.1: should we insert at end of list **/
        if(temp==0)
            temp1->next_name = desiredNode;

        /** Step 2.2.2: should we insert in middle or beginning of list **/
         else {

            /** Step 2.2.2.a: here we check if there's an element before our desired Node **/
           /** if there is then we're inserting in middle of the list **/
           if(temp1!=0)
                temp1->next_name=desiredNode;

            /** Step 2.2.2.b: if not then we are inserting at the beginning of the list **/
            else
                p = desiredNode;
        }

    }


}

/** ## END OF POINTER IMPLEMENTATION ##**/

/** ## START OF arr IMPLMENTATION ## **/
typedef struct{
    string arr[MAX];
    unsigned length;
}list;

list myList1;
void init(list &l){
    l.length = 0;
}
void traverse_forward(list &l){
    for(int i=0;i<l.length;i++)
        cout << l.arr[i] << ",";
}

void traverse_backward(list &l){
    if(l.length!=0)
        for(int i=l.length-1;i>=0;i--)
            cout << l.arr[i] << ",";
}

void insert_name(string name,list &l){
    if(l.length==MAX)
        cout<< "List is full !"<<endl;
    else {
        /** Am i inserting first element? **/
        if(l.length==0){
            l.arr[0] = name;
            l.length++;
        } else{

            /** attempting to insert in the middle of the list **/
            for(int i=0; i<l.length; i++){

                if(convert_string(name) <= convert_string(l.arr[i])) { /** Found where i should insert ! **/

                    for(int j=l.length-1;j>=i;j--){ /** Now i need to shift my elements **/
                        l.arr[j+1] = l.arr[j];
                    }

                    /** now apply the new name at p **/
                    l.arr[i] = name;
                    l.length++;
                    return;
                }
            }

            cout<< "reached the end of list";
            /** if the for loop ended without any insertion then we must be inserting at the end of the list **/
            l.arr[l.length] = name;
            l.length++;
        }
    }
}

void delete_entry(list &l,unsigned p){ /** Method to delete entry at certain position **/
    if(p >= l.length || p < 0)
        cout << "No such position." << endl;
    else {
        if(l.length==p+1)
            l.arr[p] = "";
        else
            for(int i=p; i<l.length; i++) /** Move the elements to the left since we deleted our entry**/
                l.arr[i]=l.arr[1+i];

        l.length--; /** Decrease our length since we deleted the entry **/
    }
}

int search_name(list &l,string name){
    for(int i=0;i<l.length;i++)
        if( convert_string(l.arr[i]) == convert_string(name))
            return i+1; /** I found the name at position i ! **/

    return -1; /** I couldn't find the name :( **/
}

/** ## END OF arr IMPLEMENTATION ## **/
/** ## MENU FUNCTION IMPLEMENTATION ## **/
void print_stuff(char in){
    bool run=true;
    if(in == 'A'){
        while(run){
            char input;
            string name="";
            int position;
            cout << "->";
            cin >> input;
            switch(input){
                case 'a':
                    cout << "Insert a name : ";
                    cin >> name;
                    insert_name(name,myList1);
                    break;
                case 'b':
                    cout << "Enter position ";
                    cin >> position;
                    delete_entry(myList1,position);
                    break;
                case 'c':
                    cout << "Enter name to search ";
                    cin >> name;
                    position = search_name(myList1,name);
                    cout << "Found your search at position " << position << endl;
                    break;
                case 'd':
                    traverse_forward(myList1);
                    break;
                case 'e':
                    traverse_backward(myList1);
                    break;
                case 'q':
                    run=false;
                    cout << "Exit." << endl;
                    break;
                default:
                    cout << "No such option." << endl;
                    break;
            }

        }
    } else{
        while(run){
            char input;
            string name;
            int position;
            cout << "->";
            cin >> input;
            switch(input){
                case 'a':
                    cout << "Insert a name : ";
                    cin >> name;
                    insert_pointer(myList2,name);
                    break;
                case 'b':
                    cout << "Enter the position : ";
                    cin >> position;
                    delete_pointer(myList2,position);
                    break;
                case 'c':
                    cout << "Enter a name to search " << endl;
                    cin >> name;
                    position = search_pointer(myList2,name);
                    cout << "Found your search at " << position << endl;
                    break;
                case 'd':
                    forward_pointer(myList2);
                    break;
                case 'e':
                    backward_pointer(myList2);
                    break;
                case 'q':
                    run=false;
                    cout << "Exit." << endl;
                    break;
                default:
                    cout << "No such option." << endl;
                    break;
            }

        }
    }
}

/** ## END OF MENU IMPLEMENTATION ## **/
int main() {
    init(myList1);                /** initialize our list of arr using arr. **/
    init_pointer(myList2);  /** initialize our list of arr using pointer. **/
    char input;
    cout << "Which implementation you want to use ? (A/P) : " <<endl;
    cin >> input;
    cout << "=================" << endl;
    cout << "a. Insert name :" << endl;
    cout << "b. Delete name :"<< endl;
    cout << "c. Search name :"<< endl;
    cout << "d. Traverse FW :"<< endl;
    cout << "e. Traverse BW :"<<endl;
    cout << "================="<< endl;
    switch(input){
        case 'A':
                print_stuff(input);
            break;
        case 'P':
                print_stuff(input);
            break;
        default:
            cout << "No such implementation ! " << endl;
            break;
    }

    return 0;
}
