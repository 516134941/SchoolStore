#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("data1Name");
    db.setDatabaseName("data2.db");
    db.setUserName("datauser");
    db.setPassword("123456");
    if (!db.open()) {
        //提示出错
        return false;
    }
    QSqlQuery query;
    query.exec("create table users("
               "user_id varchar(20) primary key,"
               "password varchar(20) ,"
               "authority vachar(20),"
               "treasure float,"
               "email vachar(20),"
               "tel vachar(20),"
               "explain vachar(100))"
               );
    query.exec("create table store("
               "store_id int primary key,"
               "store_name varchar(30),"
               "user_id varchar(20),"
               "area_id int)"
               );
    query.exec("create table area("
               "area_id int primary key,"
               "area_name varchar(20))"
                );
    query.exec("create table goods("
               "goods_id int primary key,"
               "goods_name varchar(20),"
               "goods_price float,"
               "store_id int,"
               "goods_dscrb varchar(50))"
               );
    query.exec("create table goods_num("
               "goods_id int primary key,"
               "goods_sum int)"
                );

    query.exec("create table shopping_car("
               "user_id varchar(20) ,"
               "goods_id int)"
               );
    query.exec("create table user_address("
               "user_id varchar(20),"
               "user_addr varchar(80))"
               );
    query.exec(QString("insert into users values('huang', '123456', 'admin',2000,'53748285@qq.com','12345325867','走自己的路')"));
    query.exec(QString("insert into users values('pan','654321','admin',2000,'979599849@qq,com','13027213865','卧槽~')"));
    //店铺数据库
    query.exec(QString("insert into store values(1001,'11S204小店','黄晨帆',1001)"));
    query.exec(QString("insert into area values(1001,'南昌东')"));
    //商品数据库
    query.exec(QString("insert into goods values(10001,'香甜王香肠',1.5,1001,'双汇 润口香甜王香肠')"));
    query.exec(QString("insert into goods_num values(10001,100)"));
    query.exec(QString("insert into goods values(10002,'鸡肉肠',1.5,1001,'双汇 鸡肉肠 70g/根')"));
    query.exec(QString("insert into goods_num values(10002,100)"));
    query.exec(QString("insert into goods values(10003,'劲爽老坛酸菜牛肉面',3,1001,'康师傅 劲爽老坛酸菜牛肉面')"));
    query.exec(QString("insert into goods_num values(10003,100)"));
    query.exec(QString("insert into goods values(10004,'劲爽红烧牛肉面',3,1001,'康师傅 劲爽红烧牛肉面')"));
    query.exec(QString("insert into goods_num values(10004,100)"));
    query.exec(QString("insert into goods values(10005,'辣鸡味点心面',2,1001,'卫来 墨西哥辣鸡味点心面')"));
    query.exec(QString("insert into goods_num values(10005,100)"));
    query.exec(QString("insert into goods values(10006,'又一餐黑米紫薯粥',5,1001,'达利园 又一餐黑米紫薯粥')"));
    query.exec(QString("insert into goods_num values(10006,100)"));
    query.exec(QString("insert into goods values(10007,'又一餐红豆薏米粥',5,1001,'达利园 又一餐红豆薏米粥')"));
    query.exec(QString("insert into goods_num values(10007,100)"));
    query.exec(QString("insert into goods values(10008,'优乐香芋味美奶茶',5,1001,'喜之郎 优乐香芋味美奶茶')"));
    query.exec(QString("insert into goods_num values(10008,100)"));

    //麻辣有味区
    query.exec(QString("insert into goods values(20001,'亲嘴烧A',1.5,1001,'卫龙 亲嘴烧A 红烧牛肉味')"));
    query.exec(QString("insert into goods_num values(20001,100)"));
    query.exec(QString("insert into goods values(20002,'亲嘴烧C',1.5,1001,'卫龙 亲嘴烧C 川香风味')"));
    query.exec(QString("insert into goods_num values(20002,100)"));
    query.exec(QString("insert into goods values(20003,'亲嘴烧B',1.5,1001,'卫龙 亲嘴烧B 麦辣鸡汁味')"));
    query.exec(QString("insert into goods_num values(20003,100)"));
    query.exec(QString("insert into goods values(20004,'鸽鸽豆角干',1.5,1001,'鸽鸽豆角干（麻辣味）28g')"));
    query.exec(QString("insert into goods_num values(20004,100)"));
    query.exec(QString("insert into goods values(20005,'香辣素牛板筋',3,1001,'香辣素牛板筋')"));
    query.exec(QString("insert into goods_num values(20005,100)"));
    query.exec(QString("insert into goods values(20006,'麦香鸡汁味亲嘴烤',0.7,1001,'卫龙 麦香鸡汁味亲嘴烤')"));
    query.exec(QString("insert into goods_num values(20006,100)"));
    query.exec(QString("insert into goods values(20007,'大面筋',3,1001,'卫到 大面筋 65g/袋')"));
    query.exec(QString("insert into goods_num values(20007,100)"));
    query.exec(QString("insert into goods values(20008,'面筋怀旧',2,1001,'麻辣王子面筋怀旧26g')"));
    query.exec(QString("insert into goods_num values(20008,100)"));
    query.exec(QString("insert into goods values(20009,'大面筋',5,1001,'卫龙 大面筋 106g/袋')"));
    query.exec(QString("insert into goods_num values(20009,100)"));
    query.exec(QString("insert into goods values(20010,'红烧牛肉味亲嘴烧',0.7,1001,'卫龙 红烧牛肉味亲嘴烧')"));
    query.exec(QString("insert into goods_num values(20010,100)"));
    query.exec(QString("insert into goods values(20011,'鸽鸽豆角干',2.5,1001,'鸽鸽豆角干69g')"));
    query.exec(QString("insert into goods_num values(20011,100)"));
    query.exec(QString("insert into goods values(20012,'素食烤鸭',2.5,1001,'素食烤鸭')"));
    query.exec(QString("insert into goods_num values(20012,100)"));
    return true;
}


#endif // CONNECTION_H
