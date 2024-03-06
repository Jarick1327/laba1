#include <iostream> //потоки ввода и вывода
#include <math.h> //необходима arcsin и sin

using namespace std; //cin cout
const double pi = M_PI; //M_PI из math.h

struct point {
    int x;
    int y;
};

struct polygon{
    int n_vertexes;
    double a_side_length;
    double Perimeter;
    double R_spoke;
    double S_area;
    point V1;
    point* ptr_array_vertaxes = new point [n_vertexes];
};


double count_Perimeter(polygon* ptr_polygon_i);
double count_R_spoke(polygon* ptr_polygon_i);
double count_S_area(polygon* ptr_polygon_i);

void input_polygon(polygon* ptr_polygon_i);
void show_polygon(polygon* ptr_polygon_i);
void help();
//void clear();
//void back_to_menu();
//void close();


int main()
{
    setlocale(LC_ALL, "\Russian"); //разрешает использовать кириллицу
    // (у меня на ноутбуке по умолчанию 30 строчек)
    system("mode con lines=30");

    int i_polygones = -1;
    polygon* ptr_polygones;
    char control_char = '0';

    while (control_char != 'e') { //eng
    //меню всей программы
        //help();
        cout<<endl<<" Многоугольников сейчас: "<<(i_polygones+1)<<endl;
        cout<<" "; //строка набора, итого +2 строчки
        cin>>control_char;

        if (control_char == 'n') {
        //создаём новый многоугольник
            i_polygones = i_polygones+1;
            if (i_polygones == 0) {
                ptr_polygones = new polygon[0];
            }
            if (i_polygones >0) {
                polygon* temp = new polygon[i_polygones-1];
                //скопируем в буфер введённые данные
                for (int i=0; i<(i_polygones); i++){
                    *(temp+i) = *(ptr_polygones+i);
                }
                //больший массив
                ptr_polygones = new polygon[i_polygones];
                //скопируем в увеличенный массив
                for (int i=0; i<(i_polygones); i++){
                    *(ptr_polygones+i) = *(temp+i);
                }
                delete[] temp;
            }
            //добавим последнюю запись
            polygon* ptr_polygon_i = &ptr_polygones[i_polygones];
            input_polygon(ptr_polygon_i);

            control_char = '0';
        }

        else if (control_char == 's' && (i_polygones+1) >=1) {
        //выводим данные об одном многоугольнике
            cout<<"     Введите номер (от 1) интересующего многоугольника: ";
            int number = 0;
            //добавить проверку на -
            cin>>number;
            polygon* ptr_polygon_i = &ptr_polygones[number-1];
            show_polygon(ptr_polygon_i);
            control_char = '0';
        }

        else if (control_char == 'd' && (i_polygones+1) >1) {
        //стираем один многоугольник
            cout<<"     Введите номер (от 1) удаляемого многоугольника: ";
            int number = 0;
            //добавить проверку на -
            cin>>number;
            int index = number - 1;
            //мы работаем с i-ым
            //копируем в буфер
            i_polygones = i_polygones-1;
            if (i_polygones >= 0) {
                polygon* temp = new polygon[i_polygones+1];
                //скопируем в буфер введённые данные
                for (int i=0; i<(i_polygones); i++){
                    *(temp+i) = *(ptr_polygones+i);
                }
                //меньший массив
                ptr_polygones = new polygon[i_polygones];
                //скопируем в увменьшенный массив
                for (int i=0; i<(index); i++){
                    *(ptr_polygones+i) = *(temp+i);
                }
                for (int i=index; i<(i_polygones+1+1); i++){
                    *(ptr_polygones+i) = *(temp+i+1);
                }
                delete[] temp;
            }

            control_char = '0';
        }
    }

    //exit
    delete[] ptr_polygones;

    return 0;
}

double count_Perimeter(polygon* ptr_polygon_i) {
    double Perimeter = (double)(*ptr_polygon_i).n_vertexes * (*ptr_polygon_i).a_side_length;
    return Perimeter;
}

double count_R_spoke(polygon* ptr_polygon_i) {
    double R_spoke = (*ptr_polygon_i).a_side_length/(2*sin(pi/(*ptr_polygon_i).n_vertexes));
    return R_spoke;
}

double count_S_area(polygon* ptr_polygon_i) {
    double S_area = 0.5 * pow( (*ptr_polygon_i).R_spoke, 2.0) * (double) (*ptr_polygon_i).n_vertexes * sin((2.0*pi)/(double) (*ptr_polygon_i).n_vertexes);
    return S_area;
}

void input_polygon(polygon* ptr_polygon_i) {
    cout<<"     Введите число вершин: ";
    cin>>(*ptr_polygon_i).n_vertexes;
    //добавить проверку на !<3
    cout<<"     Введите длину стороны: ";
    cin>>(*ptr_polygon_i).a_side_length;
    (*ptr_polygon_i).Perimeter = count_Perimeter(ptr_polygon_i);

    (*ptr_polygon_i).R_spoke = count_R_spoke(ptr_polygon_i);
    (*ptr_polygon_i).S_area = count_S_area(ptr_polygon_i);

    cout<<"     Введите x вершины: ";
    cin>>(*ptr_polygon_i).V1.x;

    cout<<"     Введите y вершины: ";
    cin>>(*ptr_polygon_i).V1.y;
}

void show_polygon(polygon* ptr_polygon_i) {
    cout<<"     Число вершин = "<<(*ptr_polygon_i).n_vertexes<<endl;
    cout<<"     Длина стороны = "<<(*ptr_polygon_i).a_side_length<<endl;

    cout<<"     Периметр = "<<(*ptr_polygon_i).Perimeter<<"\n";

    //cout<<"       Длина спицы = "<<(*ptr_polygon_i).R_spoke<<endl;
    cout<<"     Площадь = "<<(*ptr_polygon_i).S_area<<endl;

    cout<<"     Координата x задаваемой вершины: "<<(*ptr_polygon_i).V1.x<<endl;
    cout<<"     Координата y задаваемой вершины: "<<(*ptr_polygon_i).V1.y<<endl;
}

/*
void output_polygon() {

}
*/

void help() {
    cout<<endl<< //1 строчка
    " Чтобы добавить многоугольник, введите n"<<endl<<
    " Чтобы посмотреть характеристики многоугольника, введите s"<<endl<<
    " Чтобы изменить, введите с"<<endl<<
    " Чтобы найти больший, введите b"<<endl<<
    " Чтобы удалить, введите d"<<endl<<
    " Чтобы завершить работу, латиницей введите e"<<endl;
    //6 смысловых строчек и 1 перевод
    //"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<< //30-8-2 штук
}

/*void clear() {
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; //30 штук
}

void back_to_menu() {
    clear();
    cout<<endl<< //1 строчка
    " Чтобы выйти в меню, введите m"<<endl<<
    //1 смысловая строчка и перевод
    endl; //набор начинается с 4 строчки
}

void close() {
    clear();
    help();
}*/
