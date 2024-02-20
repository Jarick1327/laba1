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

double count_Perimeter(polygon polygon_n) {
    polygon_n.Perimeter = (double)polygon_n.n_vertexes * polygon_n.a_side_length;
    return polygon_n.Perimeter;
}

double count_R_spoke(polygon polygon_n) {
    polygon_n.R_spoke = polygon_n.a_side_length/(2*sin(pi/polygon_n.n_vertexes));
    return polygon_n.R_spoke;
}

double count_S_area(polygon polygon_n) {
    polygon_n.S_area = 0.5 * pow(polygon_n.R_spoke, 2.0) * (double)polygon_n.n_vertexes * sin((2.0*pi)/(double)polygon_n.n_vertexes);
    return polygon_n.S_area;
}
/*
void input_polygon() {

}

void output_polygon() {

}
*/
int main()
{
    setlocale(LC_ALL, "\Russian");

    cout<<"¬ведите число сторон: ";
    polygon polygon_1;
    cin>>polygon_1.n_vertexes;
    //добавить проверку на адекват
    cout<<"¬ведите длину стороны: ";
    cin>>polygon_1.a_side_length;
    polygon_1.Perimeter = count_Perimeter(polygon_1);

    cout<<polygon_1.Perimeter<<"\n";

    polygon_1.R_spoke = count_R_spoke(polygon_1);
    polygon_1.S_area = count_S_area(polygon_1);

    cout<<polygon_1.R_spoke<<endl;
    cout<<polygon_1.S_area<<endl;



    return 0;
}

