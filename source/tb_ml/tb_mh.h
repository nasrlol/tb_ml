#ifndef TB_ML_H
#define TB_ML_H


//- supervised learning model by abdellah el morabit
//- from <math.h>
#define M_E  2.7182818284590452354	/* e */

typedef struct training_sample trainig_sample;
struct training_sample
{

};

typedef struct prediction_data predicition_data;
struct prediction_data
{
    f32     w;
    f32     y;
};


typedef struct prediction_category prediction_category;
struct category
{
    string8 name;
    predicition_data data;
};

f(f32 d) {
    return d * d;
}

internal f32
derivative(f32 x, f32 (*f)(f32)) {

  f32 h = 1e-6; // small interval to differnetiate the scope
  return (f(x + h) - f(x - h)) / (2.0 * h);
}



#endif
