----1--------tabla marcas --------

CREATE TABLE Marcas
(
ID_marcas varchar(10) not null PRIMARY KEY,
Tipos_marcas varchar(10) NOT NULL
);

----2-----Tablas Provedores-------

CREATE TABLE Proveedores
(
ID_piezas_PK varchar(10) not null PRIMARY KEY,
Producto_name varchar(10) not null,
Fecha_entrada varchar(10) not null,
CONSTRAINT FK_Provedores_Producto_name FOREIGN KEY (Producto_name) REFERENCES Marcas(ID_marcas)
);

----3---tabla Almacen------
CREATE TABLE Almacen2
(
ID_piezas_PK varchar(10) not null PRIMARY KEY,
Tipos_marcas varchar(10) not null,
Fecha_de_entrada varchar(10) not null,
Inventario_IOS varchar(10) not null,
Fecha_captura varchar(10) not null,
Inventarios varchar(10) not null,
CONSTRAINT FK_Almacen2_Fecha_de_entrada FOREIGN KEY (Fecha_de_entrada) REFERENCES Proveedores(ID_piezas_PK),
CONSTRAINT FK_Almacen2_Tipos_marcas FOREIGN KEY (Tipos_marcas) REFERENCES Marcas(ID_marcas)
);

-----4 tabla inventario -------------
CREATE TABLE Inventario
(
Inventario_IOS_PK Varchar(10) not null PRIMARY KEY,
ID_Piezas varchar(10) not null,
ID_Locacion varchar(10) not null,
ID_Existencias varchar(10) not null,
Producto_name varchar(10) not null,
CONSTRAINT FK_Inventario_ID_Piezas FOREIGN KEY (ID_Piezas) REFERENCES Almacen2(ID_piezas_PK)
);
