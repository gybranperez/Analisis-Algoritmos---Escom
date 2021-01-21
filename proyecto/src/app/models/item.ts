export class Item {
    public id ?: number;
    public inicio : number;
    public fin : number;
    public color:string = "bg-info";
    constructor(id:number, inicio : number,fin : number) {
        this.id = id;
        this.inicio = inicio;
        this.fin = fin;
      }
      public toString = () : string => {
        return ` [ ${this.inicio} , ${this.fin} ] `;
    }
}
