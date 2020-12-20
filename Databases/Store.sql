DROP DATABASE IF EXISTS STORE;
CREATE DATABASE STORE;
USE STORE;

Create Table Person(
id int primary key not null auto_increment,
name varchar(50) unique not null
);

Create Table Item(
id int primary key not null auto_increment,
name varchar(50) unique not null,
type Enum("Phone", "Tablet", "Laptop"),
price float not null
);

Create Table Store(
id int primary key not null auto_increment,
created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
person_id int not null,
item_id int not null,
Foreign key(item_id) REFERENCES Item(id),
Foreign key(person_id) REFERENCES Person(id)
);


Insert into Person(name) Values("Vladi");
Insert into Person(name) Values("Gosho");
Insert into Person(name) Values("Stamo");

Insert into Item(name, type, price) Values("Dell", "Laptop", 1000);
Insert into Item(name, type, price) Values("Mac", "Laptop", 3000);
Insert into Item(name, type, price) Values("Asus", "Laptop", 1000);
Insert into Item(name, type, price) Values("Prestigio", "Tablet", 500);
Insert into Item(name, type, price) Values("Iphone", "Phone", 2000);

Insert into Store(person_id, item_id) Values(1, 1);
Insert into Store(person_id, item_id) Values(1, 2);
Insert into Store(person_id, item_id) Values(1, 2);
Insert into Store(person_id, item_id) Values(1, 3);
Insert into Store(person_id, item_id) Values(2, 2);
Insert into Store(person_id, item_id) Values(2, 4);
Insert into Store(person_id, item_id) Values(2, 1);
Insert into Store(person_id, item_id) Values(2, 2);
Insert into Store(person_id, item_id) Values(2, 2);
Insert into Store(person_id, item_id) Values(2, 4);

#
Select Person.name, Item.name, Item.price
From Store
Left Join Item On Store.item_id = Item.id
Left Join Person On Store.person_id = Person.id;

Select Person.name
From Store
Left Join Person On Store.person_id = Person.id
Group by Person.name;

Select Item.name
From Store
Left Join Item On Item.id = Store.item_id
Group by Item.name;

Select Sum(Item.price)
From Store
Left Join Item On Item.id = Store.item_id;

Select Person.name, Sum(Item.price)
From Store
Left Join Person On Person.id = Store.person_id
Left Join Item On Item.id = Store.item_id
Group by Person.name;

DROP DATABASE IF EXISTS STORE;





