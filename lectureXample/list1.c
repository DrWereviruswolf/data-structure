//ADT of 线性表

void Union(list &la, list lb){
    int la_len, lb_len, i;
    elemType e;
    la_len = listLength(la);
    lb_len = listlength(lb);
    for(i=1;i<=lb_len;i++){
        getElem(lb,i,&e);
        if(!locateElem(la,e,equal))
            listInsert(la,++la_len,e);
    }
}//AUB

void mergeList(list la, list lb)