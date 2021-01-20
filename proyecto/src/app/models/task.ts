export class Task {
    id:number = 1;
    label:string = 'tarea ';
    description?:string;
    start:string;
    end:string;
    statusList:any = [
        {
          start: "1:00",
          color: '#18BFED'
        }
    ];
    constructor(id:number, start : number,end : number) {
        this.id = id;
        this.start = ""+start+":00";
        this.end = ""+end+":00";
        this.label = this.label + id; 
        this.statusList[0].start = ""+start+":00"; 
      }
      public toString = () : string => {
        return ` (${this.start}, ${this.end}) `;
    }
}
