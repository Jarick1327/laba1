#include <iostream> //������ ����� � ������
#include <math.h> //���������� arcsin � sin

using namespace std; //cin cout
const double pi = M_PI; //M_PI �� math.h

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
    setlocale(LC_ALL, "\Russian"); //��������� ������������ ���������
    // (� ���� �� �������� �� ��������� 30 �������)

    int i_polygones = -1;
    polygon* ptr_polygones;
    char control_char = '0';

    while (control_char != 'e') { //eng
    //���� ���� ���������
        help();
        cin>>control_char;

        if (control_char == 'n') {
        //������ ����� �������������
            i_polygones = i_polygones+1;
            if (i_polygones == 0) {
                ptr_polygones = new polygon[0];
            }
            if (i_polygones >0) {
                polygon* temp = new polygon[i_polygones-1];
                //��������� � ����� �������� ������
                for (int i=0; i<(i_polygones); i++){
                    *(temp+i) = *(ptr_polygones+i);
                }
                //������� ������
                ptr_polygones = new polygon[i_polygones];
                //��������� � ����������� ������
                for (int i=0; i<(i_polygones); i++){
                    *(ptr_polygones+i) = *(temp+i);
                }
            }
            //������� ��������� ������
            polygon* ptr_polygon_i = &ptr_polygones[i_polygones];
            input_polygon(ptr_polygon_i);
            //show_polygon(ptr_polygon_i);

            control_char = '0';
        }

        else if (control_char == 's' && (i_polygones+1) >=1) {
        //������� ������ �� ����� ��������������
            cout<<"     ������� ����� (�� 1) ������������� ��������������: ";
            int number = 0;
            //�������� �������� �� -
            cin>>number;
            polygon* ptr_polygon_i = &ptr_polygones[number-1];
            show_polygon(ptr_polygon_i);
            control_char = '0';
        }

        else if (control_char == 'd' && (i_polygones+1) >1) {
        //������� ���� �������������

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
    cout<<"     ������� ����� ������: ";
    cin>>(*ptr_polygon_i).n_vertexes;
    //�������� �������� �� !<3
    cout<<"     ������� ����� �������: ";
    cin>>(*ptr_polygon_i).a_side_length;
    (*ptr_polygon_i).Perimeter = count_Perimeter(ptr_polygon_i);

    (*ptr_polygon_i).R_spoke = count_R_spoke(ptr_polygon_i);
    (*ptr_polygon_i).S_area = count_S_area(ptr_polygon_i);

    cout<<"     ������� x �������: ";
    cin>>(*ptr_polygon_i).V1.x;

    cout<<"     ������� y �������: ";
    cin>>(*ptr_polygon_i).V1.y;
}

void show_polygon(polygon* ptr_polygon_i) {
    cout<<"     ����� ������ = "<<(*ptr_polygon_i).n_vertexes<<endl;
    cout<<"     ����� ������� = "<<(*ptr_polygon_i).a_side_length<<endl;

    cout<<"     �������� = "<<(*ptr_polygon_i).Perimeter<<"\n";

    //cout<<"       ����� ����� = "<<(*ptr_polygon_i).R_spoke<<endl;
    cout<<"     ������� = "<<(*ptr_polygon_i).S_area<<endl;

    cout<<"     ���������� x ���������� �������: "<<(*ptr_polygon_i).V1.x<<endl;
    cout<<"     ���������� y ���������� �������: "<<(*ptr_polygon_i).V1.y<<endl;
}

/*
void output_polygon() {

}
*/

void help() {
    cout<<endl<< //1 �������
    " ����� �������� �������������, ������� n"<<endl<<
    " ����� ���������� �������������� ��������������, ������� s"<<endl<<
    " ����� ��������, ������� �"<<endl<<
    " ����� ����� �������, ������� b"<<endl<<
    " ����� �������, ������� d"<<endl<<
    " ����� ��������� ������, ��������� ������� e"<<endl<<
    //6 ��������� ������� � 1 �������
    //"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<< //30-9 ����
    endl<<" "; //������ ������
}

/*void clear() {
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; //30 ����
}

void back_to_menu() {
    clear();
    cout<<endl<< //1 �������
    " ����� ����� � ����, ������� m"<<endl<<
    //1 ��������� ������� � �������
    endl; //����� ���������� � 4 �������
}

void close() {
    clear();
    help();
}*/
