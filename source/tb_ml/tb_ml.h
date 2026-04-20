//- supervised learning model by abdellah el morabit

#ifndef TB_ML_H
#define TB_ML_H

//- source: <math.h>
read_only global_variable
u64 epochs = 100;

read_only global_variable f32 m_e = 2.7182818284590452354f; // e


// traning sample
typedef struct ts ts;
struct ts
{
    f32     w, y;
};


typedef struct model model;
struct model
{
    f32 value;
};


#endif
