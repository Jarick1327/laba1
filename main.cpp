#include <iostream>
#include <math.h>

using namespace std;
const double pi = M_PI;

struct polygon{
    int n_vertexes;
    double a_side_length;
    double Perimeter;
    double R_spoke;
    double S_area;
};
//исправить указатели
double count_Perimeter(int ptr_polygon_i) {
    double Perimeter = (double)ptr_polygon_i.n_vertexes * ptr_polygon_i.a_side_length;
    return Perimeter;
}

double count_R_spoke(int ptr_polygon_i) {
    R_spoke = ptr_polygon_i.a_side_length/(2*sin(pi/ptr_polygon_i.n_vertexes));
    return R_spoke;
}

double count_S_area(int ptr_polygon_i) {
    S_area = 0.5 * pow(ptr_polygon_i.R_spoke, 2.0) * (double)ptr_polygon_i.n_vertexes * sin((2.0*pi)/(double)ptr_polygon_i.n_vertexes);
    return S_area;
}

void input_polygon(int ptr_polygon_i) {
    cout<<"Введите число сторон: ";
    cin>>ptr_polygon_i.n_vertexes;
    //добавить проверку на адекват
    //cout<<ptr_polygon_i.n_vertexes<<endl;
    cout<<"Введите длину стороны: ";
    cin>>ptr_polygon_i.a_side_length;
    //cout<<ptr_polygon_i.a_side_length<<endl;

    ptr_polygon_i.Perimeter = count_Perimeter(ptr_polygon_i);
    cout<<ptr_polygon_i.Perimeter<<"\n";

    ptr_polygon_i.R_spoke = count_R_spoke(ptr_polygon_i);
    ptr_polygon_i.S_area = count_S_area(ptr_polygon_i]);

    cout<<ptr_polygon_i.R_spoke<<endl;
    cout<<ptr_polygon_i.S_area<<endl;*/
}
/*
void output_polygon() {

}
*/
int main()
{
    setlocale(LC_ALL, "\Russian");

    char input = '0';
    int i_polygones = -1;
    polygon* ptr_polygones;
    cout<<"Если хотите добавить многоугольник, введите n: ";
    cin>>input;
    if (input == 'n') {
        i_polygones = i_polygones+1;
        try {
            ptr_polygones = new polygon[i_polygones+1];
        }
        catch(const bad_alloc& e) {
        cout<<"Error: "<<e.what()<<endl;
        }
        polygon* ptr_polygon_i = ptr_polygones[i_polygones];

        input_polygon(ptr_polygon_i);
    }



    /*
    cout<<"Введите число сторон: ";
    polygon polygon_1;
    cin>>polygon_1.n_vertexes;
    //добавить проверку на адекват
    cout<<"Введите длину стороны: ";
    cin>>polygon_1.a_side_length;
    polygon_1.Perimeter = count_Perimeter(polygon_1);

    cout<<polygon_1.Perimeter<<"\n";

    polygon_1.R_spoke = count_R_spoke(polygon_1);
    polygon_1.S_area = count_S_area(polygon_1);

    cout<<polygon_1.R_spoke<<endl;
    cout<<polygon_1.S_area<<endl;*/

    delete[] ptr_polygones;
    return 0;
}
