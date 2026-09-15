#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int columnWidth = 15;

    cout << setw(columnWidth) << "Name"
    << setw(columnWidth) << "Score"
    << setw(columnWidth) << "Average" << endl;

    cout << setw(columnWidth) << "Alex"
    << setw(columnWidth) << 87
    << setw(columnWidth) << 91.5 << endl;

    return 0;
}

/*
setw() reserves columns or slots (field width) a value can occupy.

The modifier is non-sticky and applies only to the next item to be displayed. Meaning
it has to be reinvoked for additional values that need to use it.

Content in the field width is right justified by default. Unused slots will be
occupied with a space, but that can be replaced with setfill().

Values exceeding the field width automatically add more slots or spaces as needed.

*/