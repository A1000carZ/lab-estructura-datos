#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

void endOperation(int choice);
void imprimir(int[], int n);
void initManual(int[], int n);
void initRandom(int[], int n);
int getMax(int[], int n);
int getMin(int[], int n);
float getProm(int[], int n);
void getValuesHigherProm(int[], int n);
void cleanList(int[], int n);
int searchItem(int[], int sizeList, int item);
void searchFunction(int[], int sizeList);
void searchAndReplaceItem(int[], int n);
int insertFirstIndex(int[], int lastIndex);
int insertLastIndex(int[], int sizeList);
int insertMiddleIndex(int[], int sizeList);
int deleteFirstIndex(int[], int sizeList);
int deleteLastIndex(int[], int sizeList);
void bubbleSort(int[], int sizeList);
void directInsertionSort(int[], int sizeList);

int main()
{
    int choice, sizeList, lastIndex = 0, item;

    cout << endl
         << "\t\tOperaciones con arreglos" << endl
         << endl;
    cout << "\tCuantos datos quieres manejar en tu lista? : ";

    cin >> sizeList;

    int array[30] = {0};

    for (int i = 0; i < sizeList; i++)
    {
        array[i] = 0;
    }

    cout << endl;
    lastIndex = sizeList;
    system("clear");

    while (1)
    {
        cout << "\tTamaño de lista: " << sizeList << endl;
        imprimir(array, sizeList);
        cout << "\t\tOperaciones con arreglos" << endl
             << endl;
        cout << "\t0. Imprimir lista" << endl;
        cout << "\t1. Asignar manualmente datos a la lista" << endl;
        cout << "\t2. Asignar aleatoriamente datos a la lista" << endl;
        cout << "\t3. Obtener la sumatoria de la lista" << endl;
        cout << "\t4. Obtener el valor maximo de la lista" << endl;
        cout << "\t5. Obtener el valor minimo de la lista" << endl;
        cout << "\t6. Obtener el valor promedio de la lista" << endl;
        cout << "\t7. Obtener los valores mayores al promedio de la lista" << endl;
        cout << "\t8. Limpiar la lista" << endl;
        cout << "\t9. Buscar un valor en la lista" << endl;
        cout << "\t10. Buscar un valor en la lista y modificarlo" << endl;
        cout << "\t11. Insertar un valor al principio de la lista" << endl;
        cout << "\t12. Insertar un valor al final de la lista" << endl;
        cout << "\t13. Insertar un valor en medio de la lista" << endl;
        cout << "\t15. Eliminar el primero de la lista" << endl;
        cout << "\t16. Eliminar el ultimo de la lista" << endl;
        cout << "\t17. Bubble sort" << endl;
        cout << "\t18. Direct Insertion Sort" << endl;
        cout << "\t19. Eliminar el ultimo de la lista" << endl;
        cout << endl
             << "\tSelecciona una opcion: ";
        cin >> choice;

        cout << endl;

        switch (choice)
        {
        case 0:
            imprimir(array, sizeList);
            endOperation(choice);
            break;
        case 1:
            initManual(array, sizeList);
            endOperation(choice);
            break;
        case 2:
            initRandom(array, sizeList);
            endOperation(choice);
            break;
        case 3:
            break;
        case 4:
            cout << "\tEl numero maximo es: " << getMax(array, sizeList) << endl;
            endOperation(choice);
            break;
        case 5:
            cout << "\tEl numero minimo es: " << getMin(array, sizeList) << endl;
            endOperation(choice);
            break;
        case 6:
            cout << "\tEl promedio de tu lista es: " << getProm(array, sizeList) << endl;
            endOperation(choice);
            break;
        case 7:
            cout << "\tLos valores mayores al promedio de tu lista es: " << endl;
            getValuesHigherProm(array, sizeList);
            cout << endl;
            endOperation(choice);
            break;
            break;
        case 8:
            cleanList(array, sizeList);
            endOperation(choice);
            break;
        case 9:
            searchFunction(array, sizeList);
            endOperation(choice);
            break;
        case 10:
            searchAndReplaceItem(array, sizeList);
            endOperation(choice);
            break;
        case 11:
            lastIndex = insertFirstIndex(array, lastIndex);
            sizeList = lastIndex;
            endOperation(choice);
            break;
        case 12:
            lastIndex = insertLastIndex(array, sizeList);
            sizeList = lastIndex;
            endOperation(choice);
            break;
        case 13:
            lastIndex = insertMiddleIndex(array, sizeList);
            sizeList = lastIndex;
            endOperation(choice);
            break;
        case 14:
            searchAndReplaceItem(array, sizeList);
            endOperation(choice);
            break;
        case 15:
            lastIndex = deleteFirstIndex(array, sizeList);
            sizeList = lastIndex;
            endOperation(choice);
        case 16:
            lastIndex = deleteLastIndex(array, sizeList);
            sizeList = lastIndex;
            endOperation(choice);
        case 17:
            bubbleSort(array, sizeList);
        case 18:
            directInsertionSort(array,sizeList);
        default:
            break;
        }
    }

    return 0;
}

void searchFunction(int array[], int sizeList)
{
    int item;
    cout << "\tIngresa el numero a buscar: ";
    cin >> item;
    int n = searchItem(array, sizeList, item);
    if (n != -1)
    {
        cout << "\tEl numero " << item << " se encuentra en la lista!" << endl;
    }
    else
    {
        cout << "\tLo siento no lo he encontrado" << endl;
    }
}

void endOperation(int choice)
{
    switch (choice)
    {
    case 0:
        cout << endl
             << "\tMostrado exitosamente!" << endl;
        break;
    case 1 ... 3:
        cout << endl
             << "\tGuardado exitosamente!" << endl;
        break;
    case 4 ... 6:
        cout << endl
             << "\tEncontrado exitosamente!" << endl;
        break;
    case 7 ... 10:
        cout << endl
             << "\tRealizado exitosamente!" << endl;
        break;
    default:
        break;
    }
    cout << "\t-----------------------------" << endl;
    sleep(2);
    system("clear");
}

void imprimir(int array[], int n)
{
    cout << "\tEstado de mi lista: [";
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl
         << endl;
}

void initManual(int array[], int n)
{
    cout << "\tIntroduce " << n << " numeros: " << endl;
    cout << "\t[" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\t- ";
        cin >> array[i];
        if (i < n - 1)
        {
            cout << endl;
        }
    }
    cout << "\t]" << endl;
}

void initRandom(int array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        array[i] = 1 + rand() % 100;
    }
}

int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int getMin(int array[], int n)
{
    int min = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

float getProm(int array[], int n)
{
    int sum = array[0];
    for (int i = 1; i < n; i++)
    {
        sum += array[i];
    }

    float prom = (float)sum / n;
    return prom;
}

void getValuesHigherProm(int array[], int n)
{
    float promedio = getProm(array, n);
    int count = 0;
    int nArray[n];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > promedio)
        {
            nArray[count++] = array[i];
        }
    }

    int filterArray[count];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nArray[i] != 0)
        {
            filterArray[j++] = nArray[i];
        }
    }

    imprimir(filterArray, count);
}

void cleanList(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
    }

    imprimir(array, n);
}

int searchItem(int array[], int sizeList, int item)
{
    int i, Rpos = -1, flag = 0;
    for (i = 0; i < sizeList; i++)
    {
        if (array[i] == item)
        {
            flag = 1;
            Rpos = i;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "El valor no se encontro por ningun lado\n";
    }
    return Rpos;
}

void searchAndReplaceItem(int array[], int n)
{
    int item, newItem;
    bool founded = false;
    cout << "\tIngresa el numero a buscar: ";
    cin >> item;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == item)
        {
            founded = true;
        }
    }

    if (founded)
    {
        cout << "\tEl numero " << item << " se encuentra en la lista!" << endl;
        cout << "\tPor cual numero lo deseas reemplazar: ";
        cin >> newItem;
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            if (array[i] == item)
            {
                array[i] = newItem;
            }
        }
    }
    else
    {
        cout << "\tLo siento no lo he encontrado" << endl;
    }
}

int insertFirstIndex(int array[], int lastIndex)
{
    int i, count = 1;
    int number;
    char answer;
    bool isReturn = false;

    while (!isReturn)
    {
        if (lastIndex == -1)
        {
            lastIndex = 0;
            cout << "\tingresa el dato en el arreglo: ";
            cin >> array[0];
        }
        else
        {
            if (lastIndex < 29)
            {
                lastIndex++;
                for (i = lastIndex; i > 0; i--)
                {
                    array[i] = array[i - 1];
                }
                cout << "\tIngresa el dato a agregar: ";
                cin >> array[0];
                cout << endl;
            }
            else
            {
                cout << "\tYa no puedes agregar más datos" << endl;
            }
        }
        imprimir(array, (lastIndex));
        cout << endl
             << "\tDeseas agregar otro dato?" << endl;
        cout << "\t[s] si [n] no ";
        cin >> answer;
        cout << endl;
        if (answer == 'n' || answer == 's')
        {
            if (answer == 'n')
                isReturn = true;
            else
            {
                isReturn = false;
            }
        }
        else
        {
            cout << endl
                 << "\tNo pudimos procesar su respuesta" << endl;
            isReturn = true;
        }
    }
    return lastIndex;
}

int insertLastIndex(int array[], int sizeList)
{
    int number;
    char answer;
    bool isReturn = false;

    while (!isReturn)
    {
        if (sizeList < 29)
        {
            sizeList++;
            cout << "\tIngrese el dato a agregar: ";
            cin >> array[sizeList - 1];
        }
        else
        {
            cout << "\tYa no puedes agregar mas datos \n";
        }
        imprimir(array, (sizeList));
        cout << endl
             << "\tDeseas agregar otro dato?" << endl;
        cout << "\t[s] si [n] no ";
        cin >> answer;
        cout << endl;
        if (answer == 'n' || answer == 's')
        {
            if (answer == 'n')
                isReturn = true;
            else
            {
                isReturn = false;
            }
        }
        else
        {
            cout << endl
                 << "\tNo pudimos procesar su respuesta" << endl;
            isReturn = true;
        }
    }
    return sizeList;
}

int insertMiddleIndex(int array[], int sizeList)
{
    int temp, i, j, k, input1, input2;

    imprimir(array, sizeList);

    cout << "\tQuiero que insertes en medio de" << endl;
    cout << "\t";
    cin >> input1;
    cout << "\t y ";
    cout << "\t";
    cin >> input2;

    int value1 = searchItem(array, sizeList, input1);
    int value2 = searchItem(array, sizeList, input2);

    cout << "\t" << value1 << "\t y " << endl
         << "\n\t" << value2;

    cout << endl;

    if (value1 == -1 || value2 == -1)
    {
        cout << "\tAlguno de los valores no se encuentra en la lista." << endl;
    }
    else if (abs(value1 - value2) == 1)
    {
        int middleIndex = (value1 + value2) / 2;
        if (sizeList >= 30)
        {
            cout << "Ya no puedes agregar mas valores\n";
        }
        else
        {
            for (i = 1; i <= 2; i++)
            {
                sizeList++;
                for (j = sizeList; j > middleIndex; j--)
                {
                    array[j] = array[j - 1];
                }
            }
            for (k = middleIndex + 1; k < middleIndex + 3; k++)
            {
                cout << "\tIngrese el dato a agregar: ";
                cin >> array[k];
            }
        }
    }
    else
    {
        cout << "\tLos valores no estan adyacentes." << endl;
    }

    return sizeList;
}

int deleteFirstIndex(int array[], int sizeList)
{
    int i;
    for (i = 0; i < sizeList - 1; i++)
    {
        array[i] = array[i + 1];
    }
    return sizeList;
}

int deleteLastIndex(int array[], int sizeList)
{
    array[sizeList] = 0;
    sizeList--;
    return sizeList;
}

void bubbleSort(int array[], int sizeList)
{
    for (int i = 0; i < sizeList - 1; i++)
    {
        cout << "\tPasada No. " << i + 1 << endl;
        for (int j = 0; j < sizeList - 1; j++)
        {
            cout << "\t" << array[j] << " > " << array[j + 1] << " ";
            if (array[j] > array[j + 1])
            {
                cout << "V ";
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                imprimir(array, sizeList);
            }
            else
            {
                cout << "F ";
                imprimir(array, sizeList);
            }
        }
    }
}

void directInsertionSort(int array[], int sizeList)
{
    for (int i = 0; i < sizeList; i++)
    {
        cout << "\tPasada No. "<< i+1<<endl;
        int element = array[i];
        for(int j=0; j < i+1; j++){
            cout << "\t"<<element<<" < "<<array[j+1];
            if (element < array[j])
            {
                cout << " V ";
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                imprimir(array, sizeList);
            }
            else
            {
                cout << " F ";
                imprimir(array, sizeList);
            }
        }
    }
}


