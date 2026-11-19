int main()
{
    // Test with integer arrays
    MyArray<int> array1(3) ;
    array1[0] = 1 ;
    array1[1] = 2 ;
    array1[2] = 3 ;

    MyArray<int> array2(3) ;
    array2[0] = 4 ;
    array2[1] = 5 ;
    array2[2] = 6 ;

    // Display initial arrays
    cout << "array1: " << array1 << endl ;
    cout << "array2: " << array2 << endl ;

    // Test indexing operator and getSize()
    cout << "array1[1]: " << array1[1] << endl ;
    cout << "array1 size: " << array1.getSize() << endl ;

    // Test equality with arrays of different sizes
    MyArray<int> array3(1) ;
    array3[0] = 1 ;
    cout << "array1 == array3 (different sizes): "
         << (array1 == array3 ? "True" : "False") << endl ;

    // Test assignment operator with arrays of different sizes
    array3 = array1 ;
    cout << "array3 (after assignment from array1): " << array3 << endl ;

    // Test equality operator after assignment
    cout << "array1 == array2: " << (array1 == array2 ? "True" : "False") << endl ;
    cout << "array1 == array3: " << (array1 == array3 ? "True" : "False") << endl ;

    // Modify array3 and show that array1 remains unchanged
    array3[1] = 20 ;
    cout << "Modified array3: " << array3 << endl ;
    cout << "array1 (should be unchanged): " << array1 << endl ;
    cout << "array1 == array3 (after modification): "
         << (array1 == array3 ? "True" : "False") << endl ;

    // Test addition operator
    MyArray<int> arraySum = array1 + array2 ;
    cout << "array1 + array2: " << arraySum << endl ;

    // Test with double arrays
    MyArray<double> array4(3) ;
    array4[0] = 1.1 ;
    array4[1] = 2.2 ;
    array4[2] = 3.3 ;
    cout << "array4: " << array4 << endl ;

    // Test copy constructor and verify deep-copy behavior
    MyArray<double> array5 = array4 ;
    cout << "array5 (copied from array4): " << array5 << endl ;

    array5[0] = 9.9 ;
    cout << "Modified array5: " << array5 << endl ;
    cout << "array4 (should be unchanged): " << array4 << endl ;

    // Test addition with double arrays
    MyArray<double> array6 = array4 + array5 ;
    cout << "array4 + array5: " << array6 << endl ;

    return 0 ;
}
