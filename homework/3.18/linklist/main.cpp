#include "def.h"
#include "linklist.h"

int main() {

    cout << "Q1:Delete the fourth element:"<<endl;
    cout << "input a list:"<<endl;
    LIST l1 = createlist(5);
    cout << "before delete:";
    printlist(l1);
    deletelocate(l1,4);
    cout << "after delete:";
    printlist(l1);
    cout << endl;

    cout << "Q2:delete all duplicate elements"<<endl;
    cout << "input a list:"<<endl;
    LIST l2 = createlist(5);
    cout << "before delete:";
    printlist(l2);
    deleteduplicate(l2);
    cout << "after delete:";
    printlist(l2);
    cout << endl;

    cout << "Q3:inverse the list:"<<endl;
    cout << "input a list:"<<endl;
    LIST l3 = createlist(5);
    cout << "before inverse:";
    printlist(l3);
    cout << "after inverse:";
    inverselist(l3);
    printlist(l3);
    cout << endl;

    cout <<"Q4:cycle movement:"<<endl;
    cout << "input a list:"<<endl;
    LIST l4 = createlist(5);
    cout << "before left Move:";
    printlist(l4);
    cyclemove(l4,3,1);
    cout << "after Move 3 places to the left:";
    printlist(l4);
    cout <<"input a list:"<<endl;
    LIST l6 = createlist(5);
    cout << "before right Move:";
    printlist(l6);
    cyclemove(l6,4,0);
    cout << "after Move 4 places to the right:";
    printlist(l6);
    cout << endl;


    cout << "Q5:merge 2 lists"<< endl;
    cout << "before merge l1:";
    cout << "input a list:"<<endl;
    LIST l7 = createlist(4);
    cout << "before merge l2:";
    cout << "input a list:"<<endl;
    LIST l8 = createlist(7);
    LIST l9 = mergelist(l7,l8);
    cout << "after merge:";
    printlist(l9);
    cout << endl;


}
