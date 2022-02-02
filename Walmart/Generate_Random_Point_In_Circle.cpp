class Solution {
public:
    double r;
    double x;
    double y;
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double rad=(double)rand()/RAND_MAX;
        rad=sqrt(rad)*r;
        double angle=(double)rand()/RAND_MAX;
        angle*=360.0;
        return {x+rad*cos(angle),y+rad*sin(angle)};
        
    }
};
