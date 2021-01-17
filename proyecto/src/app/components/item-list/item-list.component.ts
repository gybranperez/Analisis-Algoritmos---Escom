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
  
  art:Item = new Item(-1,0,0);
  /*
  actividades = new Array<Item>(
                  new Item(0,1,4),
                new Item(1,3,5),
                new Item(2,0,6),
                new Item(3,5,7),
                new Item(4,3,8),
                new Item(3,5,9),
                new Item(5,6,10),
                new Item(6,8,11),
                new Item(7,8,12),
                new Item(8,2,13),
                new Item(9,12,14)
  );
  
  
    {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    {1,2},{3,4},{5,6},{2,5},{3.5}
  */
 actividades = new Array<Item>(
  new Item(0,1,2),
  new Item(1,3,4),
  new Item(2,5,6),
  new Item(3,2,5),
  new Item(4,3,5)
);
  optima:Item[]=[];
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
    this.art.inicio=0;
    this.art.fin=0;    
    this.ordenarLista();
  }

  seleccionar(art:any) {
    this.art.id=art.id;
    this.art.inicio=art.inicio;
    this.art.fin=art.fin;
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
  range(start:number,end:number) {
    let ar:number[]=new Array();
    for (let index = start+1; index < end; index++) 
      ar.push(index);
    return ar;
  }
  contains(rango1:any,rango2:any){
    alert(rango1+"\n"+rango2);
    for(let e in rango1){
      if (rango2.includes(rango1[e])) {
        return true;
     }
    }
    return false;
  }
 encontrarActividades2(){
  let opciones:Item[][]=[];
  for(let y=0;y<this.actividades.length;y++){
      opciones.push([]);
  }
  this.ordenarLista();
    for(let x=0;x<this.actividades.length;x++){
      for(let j=0;j<x;j++){
        let start = this.actividades[x].inicio;
        let finish = this.actividades[j].fin;
        let rango1 = this.range(this.actividades[x].inicio, this.actividades[x].fin);
        let rango2 = this.range(this.actividades[j].inicio, this.actividades[j].fin);  
        if((finish<start) && (opciones[x].length < opciones[j].length) && this.contains(rango1,rango2)){
            opciones[x] = opciones[j];
        }
      }
       opciones[x].push(this.actividades[x]);
    }
    let max:Item[] = [];
    for(let x=0;x<opciones.length;x++){
      if(max.length < opciones[x].length){
        max = opciones[x];
      }
    }
    let t="";
    for(let op in opciones){
      t+=opciones[op]+"\n";
    }
    this.optima=max; 
 }
 encontrarActividades(){
  let opciones = new Array(this.actividades.length-1);
  this.ordenarLista();
  for (let p = this.actividades.length-2; p >= 0; p--){
    let q = p+1;
    while (q<this.actividades.length && this.actividades[q].inicio<this.actividades[p].fin) {
      q++;
    }
    opciones[p]=1;
    
  }
 }
 duracionActividad(art:Item){
  return art.fin - art.inicio;
 }
  ordenarLista(){
    this.actividades.sort((left, right) => {
      if (left.inicio < right.inicio) return -1;
      if (left.inicio > right.inicio) return 1;
      return 0;
    })
    for(let x=0;x<this.actividades.length;x++){
      this.actividades[x].id=x;
    }
  }
  
}
