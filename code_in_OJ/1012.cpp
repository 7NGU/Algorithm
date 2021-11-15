#include <iostream>
#include <cmath>

using namespace std;

class point{
    public:
        int get_x(const point *a);
        int get_y(const point *a);
        double get_angle(const point *a);
        double get_len(const point *a);
        int cmp_yx(point a, point b);
        int cmp_angle(point a, point b);
    private:
        int x;
        int y;
        double angle;
        double len;
};

int point::get_x(const point *a){
    return a->x;
}
int point::get_y(const point *a){
    return a->y;
}
double point::get_angle(const point *a){
    return a->angle;
}
double point::get_len(const point *a){
    return a->len;
}

int point::cmp_yx(point a, point b){
    if(a.get_y != b.get_y){
        return (a.get_y - b.get_y)
    }
    else{
        return (a.get_x - b.get_x)
    }
}

int point::cmp_angle(point a, point b){
    double diff_a = a.get_angle - b.get_angle;
    double diff_l = a.get_len - b.get_len;
    if(diff_a > 0){
        return -1;
    }
    else{
        if(diff_l > 0){
            return 1;
        }
        else if(diff_l < 0){
            return -1;
        }
        else{
            return 0;
        }
    }
}


int main()
{
    cout << "result" << endl;
    
    return 0;
}