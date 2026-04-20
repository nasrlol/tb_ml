//- supervised learning model by abdellah el morabit

#ifndef TB_ML_H
#define TB_ML_H

//- source: <math.h>
read_only u64 epochs = 100;
read_only f32  M_E =  2.7182818284590452354; // e


// traning sample
typedef struct ts ts;
struct ts
{
    f32     w;
    f32     y;
};


typedef struct model model;
struct model
{
    f32 value;
};


#endif
