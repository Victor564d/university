struct info{
    char fam[60];
    char name[60];
    char ochest[60];
    int age;
    char gender;
    char group[15];
} ;


struct list {
   struct info inf;
   struct list * next;
};

float sr_age(list * first, char * group){
    if (!first) return 0;
    list * temp = first;
     int count,sum;
    do {
        if ((strcmp(temp->inf.group,group)==0) && (temp->inf.gender == 'м')){
            count++;
            sum += temp->inf.age;
        }
        if (!temp->next) return (float) (sum/count);
        temp = temp->next;
        }
    while (temp->next);   
}




