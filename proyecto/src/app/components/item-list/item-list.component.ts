import { Component, OnInit } from '@angular/core';
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
  actividades = new Array<Item>(
                  new Item(0,0,3),
                new Item(1,1,6),
                new Item(2,4,6));
  num:number = this.actividades.length;
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
    for(let x=0;x<this.actividades.length;x++){
      this.actividades[x].id=x;
    }
  }

  agregar() {
    /*for(let x=0;x<this.actividades.length;x++)
    if (this.actividades[x].id==this.art.id)
    {
      alert('ya existe un articulo con dicho codigo');
      return;
    }*/
    this.actividades.push(new Item(this.actividades.length,this.art.inicio,this.art.fin));
    this.art.id=-1;
    this.art.inicio=0;
    this.art.fin=0;    
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
}
