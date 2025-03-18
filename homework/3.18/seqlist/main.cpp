#include <iostream>
using namespace std;
#include "def.h"
#include "seqlistoper.h"

int main() {
    LIST l1,l2;
    int i = 0;

    l1.elements[0] = 0;
    l1.elements[1] = 1;
    l1.elements[2] = 2;
    l1.elements[3] = 2;
    l1.elements[4] = 2;
    l1.elements[5] = 5;
    l1.elements[6] = 7;
    l1.elements[7] = 9;
    l1.elements[8] = 9;
    l1.elements[9] = 9;

    l1.last = 9;

    l2.elements[0] = 1;
    l2.elements[1] = 1;
    l2.elements[2] = 5;
    l2.elements[3] = 5;
    l2.elements[4] = 6;
    l2.elements[5] = 6;
    l2.elements[6] = 7;
    l2.elements[7] = 8;

    l2.last = 7;

    //Q5:
    cout << "Q5:merge 2 lists"<< endl;
    cout << "before merge l1:";
    printlist(l1);
    cout << "before merge l2:";
    printlist(l2);

    LIST l3 = mergelist(l1,l2);
    cout << "after merge:";
    printlist(l3);
    cout << endl;

    //Q2:
    cout << "Q2:delete all duplicate elements"<<endl;
    cout <<" before delete:";
    printlist(l1);
    deleterepeat(l1);
    cout <<" after delete:";
    printlist(l1);
    cout << endl;

    //Q1:#include "stdio.h"
    //
    //long long x = 2022111568;
    //
    //
    //int main()
    //{
    //    long double y = 210603200410156516;
    //    static char z[20] = "2022111568Ö£ÇÇÒë";
    //
    //    printf("%lld\n",x);
    //    printf("%Lf\n",y);
    //    printf("%s\n",z);
    //}
    cout << "Q1:Delete the fourth element"<<endl;
    cout <<" before delete:";
    printlist(l1);
    Delete(3,l1);
    cout <<" after delete:";
    printlist(l1);
    cout << endl;

    //Q3:
    cout << "Q3:inverse the list:"<<endl;
    cout << " before inverse:";
    printlist(l1);
    cout << " after inverse:";
    inverselist(l1,0,l1.last);
    printlist(l1);
    cout << endl;

    //Q4:
    cout <<"Q4:cycle movement:"<<endl;
    cout << " before left Move:";
    printlist(l2);
    movecycle(l2,3,1);
    cout << " after Move 3 places to the left:";
    printlist(l2);
    cout << " before right Move:";
    printlist(l2);
    movecycle(l2,4,0);
    cout << " after Move 4 places to the right:";
    printlist(l2);

}
