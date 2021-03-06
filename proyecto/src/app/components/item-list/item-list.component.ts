import { Component, OnInit } from '@angular/core';
import { Tarjeta } from 'src/app/interfaces/tarjeta';
import { Item } from 'src/app/models/item';

@Component({
  selector: 'app-item-list',
  templateUrl: './item-list.component.html',
  styleUrls: ['./item-list.component.css']
})


export class ItemListComponent implements OnInit {


  constructor() { }

  ngOnInit(): void {
  }
  
  art:Item = new Item(-1,1,2);
  
  actividades = new Array<Item>(
                  new Item(0,1,4),
                new Item(1,3,5),
                new Item(2,5,7),
                //new Item(3,3,8),
                new Item(4,5,9),
                new Item(5,6,10),
                new Item(6,8,11),
                new Item(7,8,12),
                //new Item(8,2,13),
                new Item(9,12,14)
  );
  
  /*
    {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    {1,2},{3,4},{5,6},{2,5},{3.5}
  
 actividades = new Array<Item>(
  new Item(0,1,2),
  new Item(4,3,7),
  new Item(1,2,5),
  new Item(2,4,5),
  new Item(3,2,4)
  
);*/
mostrarAnimacion:boolean=false;
  optima:Item[]=[];
  info:string="";
  log="";
  rango={
    inicio:1,
    fin:1
  };
  porcentajeAncho:number=0;
  hayRegistros() {
    return this.actividades.length>0;              
  }

  borrar(art:any) {
    for(let x=0;x<this.actividades.length;x++)
      if (this.actividades[x].id==art.id)
      {
        this.actividades.splice(x,1);
        return;
      }
    this.ordenarLista();
    console.log("Despues de borrar: " + this.actividades);
  }

  agregar() {
    this.actividades.push(new Item(this.actividades.length,this.art.inicio,this.art.fin));
    this.art.id=-1;
    this.art.inicio=1;
    this.art.fin=2;   
    this.ordenarLista();
  }

  seleccionar(art:any) {
    this.art.id=art.id;
    this.art.inicio=art.inicio;
    this.art.fin=art.fin;
  }
  calcularAncho(art:any){
    let val = (art.fin - art.inicio) * this.porcentajeAncho;
    return val + "% !important";
  }
  calcularMargen(art:any){
    let val = (art.inicio - 1) * this.porcentajeAncho;
    return val + "% !important";
  }
  modificar() {
    for(let x=0;x<this.actividades.length;x++)
      if (this.actividades[x].id==this.art.id)
      {
        this.actividades[x].inicio=this.art.inicio;
        this.actividades[x].fin=this.art.fin;
        return;
      }        
    alert('No existe el código de articulo ingresado');
  }
  rangoActividades() {
    let rango={inicio:this.actividades[0].inicio,fin:this.actividades[0].fin};
    for (let index = 0; index < this.actividades.length; index++) {
      if (this.actividades[index].inicio < rango.inicio ) {
        rango.inicio = this.actividades[index].inicio;
      }
      if (rango.fin < this.actividades[index].fin ) {
        rango.fin = this.actividades[index].fin;
      }
    }
    this.rango=rango;
    this.log =  rango.inicio + " a " + rango.fin;
    this.porcentajeAncho= 100/rango.fin;
  }
  obtenerArreglo(){
    let a:number[] = [];
    for(let i=1;i<=this.rango.fin;i++){
      a.push(i);
    }
    return a;
  }
 encontrarActividades = async () => {
  this.mostrarAnimacion=true;
  let opciones:Item[] =[];
  for (let i = 0; i <= this.actividades.length; i++){
    opciones.push(new Item(0,0,0));
  }
  for (let i = 0; i < this.actividades.length; i++){
    this.actividades[i].color="bg-info";
  }
  this.ordenarLista();
  this.rangoActividades();
  
  this.info="Revisaremos todas las actividades...\n";
  await new Promise(resolve => setTimeout(resolve, 2500));
  for (let i = 1; i <= this.actividades.length; i++){
    opciones[i].inicio = 1;
    opciones[i].fin = i;
    let  temp = 0;
    for (let j = 1; j < i; j++){
      this.info="¿ " + this.actividades[j-1] + " termina antes que inicie " + this.actividades[i-1] + "?";
      
      this.actividades[j-1].color = "bg-warning";
      this.actividades[i-1].color = "bg-danger";
      await new Promise(resolve => setTimeout(resolve, 3500)); // 3 sec
      if(this.actividades[j-1].fin <= this.actividades[i-1].inicio){

        if (opciones[j].inicio + 1 > opciones[i].inicio) {
          this.actividades[j-1].color = "bg-success";
          let tem = opciones[i];
          opciones[i].inicio = opciones[j].inicio + 1;
          opciones[i].fin = j;
          this.info="Si, por lo tanto " + this.actividades[j-1] + " se toma en cuenta, llevamos " + opciones[i].inicio;
        await new Promise(resolve => setTimeout(resolve, 2500));
        }else{
          this.info="Ya tomamos otro elemento previamente, por lo tanto " + this.actividades[opciones[j].inicio] + " no se añade";
          await new Promise(resolve => setTimeout(resolve, 2000));
        }
        opciones[i].inicio = (opciones[i].inicio > 1 + opciones[j].inicio) ? opciones[i].inicio : 1 + opciones[j].inicio;
        
      }else{
        this.info="No lo hace, por lo tanto seguimos...";
        await new Promise(resolve => setTimeout(resolve, 800)); // 3 sec
      }
      await new Promise(resolve => setTimeout(resolve, 1000)); // 3 sec  
      this.actividades[j-1].color = (this.actividades[j-1].color=="bg-success")?"bg-success":"bg-info";
    }
    this.actividades[i-1].color = "bg-info";
  }
  let max = 0;
  let pos = -1;
  for (let i = 1; i <= this.actividades.length; i++){
    if (opciones[i].inicio > max) {
        pos = i;
        max = opciones[i].inicio;
    }
  }
  this.info="El número mayor de actividades que se pueden realizar es: " + max;
  this.optima = [];
  while(opciones[pos].inicio != 1){
    this.optima.push(this.actividades[pos-1]);
    this.actividades[pos-1].color="bg-success";
    pos = opciones[pos].fin;
  }
  this.optima.push(this.actividades[pos-1]);
  this.actividades[pos-1].color="bg-success";
 }
 duracionActividad(art:Item){
  return art.fin - art.inicio;
 }
  ordenarLista(){
    this.actividades.sort((left, right) => {
      if (left.inicio > right.inicio) return 1;
      if (left.inicio < right.inicio) return -1;
      if (left.inicio == right.inicio && left.fin < right.fin) return -1;
      if ((left.inicio == right.inicio) && (right.fin-right.inicio < left.fin-left.inicio)) return 1;
      return 0;
    })
    for(let x=0;x<this.actividades.length;x++){
      this.actividades[x].id=x;
    }
  }
  
}
