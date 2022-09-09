#ifndef DATATYPE_H_INCLUDED
#define DATATYPE_H_INCLUDED
#define sizeArr 3
#define SIZEARR 3
typedef signed char sint8_type;
typedef unsigned char uint8_type;
typedef signed short bool;
typedef unsigned short uint16_type;
typedef signed int sint32_type;
typedef unsigned int uint32_type;
typedef float float_type;
typedef double double_type;

typedef struct studentDataBase
{
  uint32_type studentId;
  uint32_type year;
  uint32_type subject[sizeArr];
  uint32_type grade[sizeArr];
  struct studentDataBase *next;
}studentDB;

typedef enum check{
false=0,
true,
};

void mainMenu();
bool SDB_Isfull(void);
uint8_type SDB_GetUsedSize(void);
bool SDB_ADDEntry(uint32_type id,uint32_type year,uint32_type *subject,uint32_type *grades);
void SDB_DeleteEntry(uint32_type id);
bool SDB_ReadEntry(uint32_type id,uint32_type *year,uint32_type *subject,uint32_type *grades);
void SDB_GetID(uint32_type *count,uint32_type *list);
bool SDB_IsIdExist(uint32_type id);



#endif // DATATYPE_H_INCLUDED
