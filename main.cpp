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

void change_perimeter(polygon* ptr_polygon_i);
void change_area(polygon* ptr_polygon_i);

void vertexes_calculate(polygon* ptr_polygon_i);

//void clear();
//void back_to_menu();
//void close();


int main()
{
    setlocale(LC_ALL, "\Russian"); //��������� ������������ ���������
    // (� ���� �� �������� �� ��������� 30 �������)
    system("mode con lines=30");

    int i_polygones = -1;
    polygon* ptr_polygones;
    char control_char = '0';

    while (control_char != 'e') { //eng
    //���� ���� ���������
        help();
        cout<<endl<<" ��������������� ������: "<<(i_polygones+1)<<endl;
        cout<<" "; //������ ������, ����� +2 �������
        cin>>control_char;

        if (control_char == 'n') {
        //������ ����� �������������
            i_polygones = i_polygones+1;
            if (i_polygones == 0) {
                ptr_polygones = new polygon[1];
            }
            if (i_polygones >0) {
                polygon* temp = new polygon[i_polygones];
                //��������� � ����� �������� ������
                for (int i=0; i<(i_polygones); i++){
                    *(temp+i) = *(ptr_polygones+i);
                }
                //������� ������
                ptr_polygones = new polygon[i_polygones+1];
                //��������� � ����������� ������
                for (int i=0; i<(i_polygones); i++){
                    *(ptr_polygones+i) = *(temp+i);
                }
                delete[] temp;
            }
            //������� ��������� ������
            polygon* ptr_polygon_i = &ptr_polygones[i_polygones+1];
            input_polygon(ptr_polygon_i);

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
            cout<<"     ������� ����� (�� 1) ���������� ��������������: ";
            int number = 0;
            //�������� �������� �� -
            cin>>number;
            int index = number - 1;
            //�� �������� � i-��
            //�������� � �����
            i_polygones = i_polygones-1;
            if (i_polygones >= 0) {
                polygon* temp = new polygon[i_polygones+1+1];
                //��������� � ����� �������� ������
                for (int i=0; i<(i_polygones+1+1); i++){
                    *(temp+i) = *(ptr_polygones+i);
                }
                //������� ������
                ptr_polygones = new polygon[i_polygones+1];
                //��������� � ������������ ������
                for (int i=0; i<(index); i++){
                    *(ptr_polygones+i) = *(temp+i);
                }
                for (int i=index; i<(i_polygones+1+1); i++){
                    *(ptr_polygones+i) = *(temp+i+1);
                }
                delete[] temp;
            }
            else {
                i_polygones = i_polygones+1;
            }
            control_char = '0';
        }

        else if (control_char == 'c' && (i_polygones+1) >=1) {
        //��������� ��������� ��� �������
            cout<<" ���� ������ ������ ����� ��������, ������� p"<<endl;
            cout<<" ���� ������ ������ ����� �������, ������� a ";
            cin>>control_char;
            if (control_char == 'p' || control_char == 'a') {
                if (control_char=='p') {
                    cout<<"     ������� ����� (�� 1) ����������� ��������������: ";
                    int number = 0;
                    //�������� �������� �� -
                    cin>>number;
                    polygon* ptr_polygon_i = &ptr_polygones[number-1];
                    change_perimeter(ptr_polygon_i);
                }
                else if (control_char=='a') {
                    cout<<"     ������� ����� (�� 1) ����������� ��������������: ";
                    int number = 0;
                    //�������� �������� �� -
                    cin>>number;
                    polygon* ptr_polygon_i = &ptr_polygones[number-1];
                    change_area(ptr_polygon_i);
                }
            }

            control_char = '0';
        }

        else if (control_char == 'b' && (i_polygones+1) >=1) {
            bool* founder[i_polygones+1];
            for (int i=0; i<(i_polygones+1); i++){
                *founder[i]=0;
            }

            cout<<" ���� ������ ����� ������� ��������, ������� p"<<endl;
            cout<<" ���� ������ ����� ������� �������, ������� a ";
            cin>>control_char;
            polygon* ptr_polygon_i = &ptr_polygones[0];
            if (control_char == 'p' || control_char == 'a') {

                //���������� ��������
                if (control_char=='p') {
                    double P_max = 0;
                    for (int i=0; i<(i_polygones+1); i++){
                        if (P_max < ((*(ptr_polygon_i+i)).Perimeter) ) {
                            P_max = (*(ptr_polygon_i+i)).Perimeter;
                        }
                    }
                    for (int i=0; i<(i_polygones+1); i++){
                            if ( (*(ptr_polygon_i+i)).Perimeter == P_max ) {
                                *founder[i]=true;
                            }
                    }
                    cout<<endl<<"       ���������� �������� = "<<P_max<<endl<<
                    "  �� � ��������������� ��� ��������:";
                    for (int i=0; i<(i_polygones+1); i++) {
                        if ( *founder[i] == 1) {
                            cout<<" "<<(i+1)<<";"<<endl;
                        }
                    }
                    cout<<" ��";
                }
                //���������� �������
                else if (control_char=='a') {
                    double A_max = 0;
                    for (int i=0; i<(i_polygones+1); i++){
                        if (A_max < ((*(ptr_polygon_i+i)).S_area) ) {
                            A_max = (*(ptr_polygon_i+i)).S_area;
                        }
                    }
                    for (int i=0; i<(i_polygones+1); i++){
                            if ( (*(ptr_polygon_i+i)).S_area == A_max ) {
                                *founder[i]=true;
                            }
                    }
                    cout<<endl<<"       ���������� ������� = "<<A_max<<endl<<
                    "  ��� � ��������������� ��� ��������:";
                    for (int i=0; i<(i_polygones+1); i++) {
                        if ( *founder[i] == 1) {
                            cout<<" "<<(i+1)<<";"<<endl;
                        }
                    }
                    cout<<" ��";
                }
            }

            control_char = '0';
        }

        else if (control_char == 'v' && (i_polygones+1) >=1) {
            cout<<"     ������� ����� (�� 1) �������������� ��� ������� ������: ";
            int number;
            cin>>number;
            polygon* ptr_polygon_i = &ptr_polygones[number-1];
            vertexes_calculate(ptr_polygon_i);

            control_char = '0';
        }
    //����� while
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
    " ����� ���������� �������, ������� v"<<endl<<
    " ����� ��������� ������, ��������� ������� e"<<endl;
    //7 ��������� ������� � 1 �������
    //"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<< //30-9-2 ����
}

void change_perimeter(polygon* ptr_polygon_i) {
    double new_Perimeter;
    cout<<"     ������� ����� ��������: ";
    cin>>new_Perimeter;
    //cout << endl<<new_Perimeter;
    (*ptr_polygon_i).Perimeter = new_Perimeter;
    (*ptr_polygon_i).a_side_length = new_Perimeter/( (double)(*ptr_polygon_i).n_vertexes );
    //������� R � S �� ����������
    (*ptr_polygon_i).R_spoke = count_R_spoke(ptr_polygon_i);
    (*ptr_polygon_i).S_area = count_S_area(ptr_polygon_i);
}

void change_area(polygon* ptr_polygon_i) {
    double new_Area;
    cout<<"     ������� ����� �������: ";
    cin>>new_Area;
    //cout << endl<<new_Area;
    (*ptr_polygon_i).S_area = new_Area;
    (*ptr_polygon_i).R_spoke = pow ( ((2*(*ptr_polygon_i).S_area) / ( ((double)(*ptr_polygon_i).n_vertexes) * sin(2*pi/((double)(*ptr_polygon_i).n_vertexes)) )), 0.5 );
    (*ptr_polygon_i).a_side_length = ((*ptr_polygon_i).R_spoke) / (2*sin(pi/ ((double)(*ptr_polygon_i).n_vertexes) ));
    //������� P �� ����������
    (*ptr_polygon_i).Perimeter = count_Perimeter(ptr_polygon_i);
}

void vertexes_calculate(polygon* ptr_polygon_i) {
    //����� ���� �� ����� OX � ���� ��������������
    double angle_phi = asin( ((*ptr_polygon_i).V1).y / ( pow( ((*ptr_polygon_i).V1).x, 2.0 )+pow( ((*ptr_polygon_i).V1).y, 2.0 ) ) );
    //����� ���� ����� - ���������� ���� ����������� n-���������
    double angle_a = ( ((*ptr_polygon_i).n_vertexes)-2 )*pi /( (*ptr_polygon_i).n_vertexes );
    point vector_to_center;
    vector_to_center.x = ((*ptr_polygon_i).V1).x - ( (*ptr_polygon_i).R_spoke * cos(angle_phi) );
    vector_to_center.y = ((*ptr_polygon_i).V1).y - ( (*ptr_polygon_i).R_spoke * sin(angle_phi) );

    point* array_vertexes = new point[ (*ptr_polygon_i).n_vertexes ];
    for (int i=0; i<( (*ptr_polygon_i).n_vertexes ); i++) {
        ( *(array_vertexes+i) ).x = ((*ptr_polygon_i).R_spoke * cos( angle_phi + pi - angle_a )) + vector_to_center.x;
        ( *(array_vertexes+i) ).y = ((*ptr_polygon_i).R_spoke * sin( angle_phi + pi - angle_a )) + vector_to_center.y;
    }

    cout<<endl;
    for (int i=0; i<( (*ptr_polygon_i).n_vertexes ); i++) {
        cout<<endl<<i<<"    x = "<< ( *(array_vertexes+i) ).x <<"   y = "<< ( *(array_vertexes+i) ).y;
    }
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
