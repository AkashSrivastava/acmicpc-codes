import java.util.*;
import java.io.*;
class Room{
   static int TotalType;//��������
   double perCharge;//ÿ���շ�
   String RoomType;//����������
   String RoomDes;//����ϸ��
   static Room room[]=new Room[10];
   
   static double RoomCharge(int TypeNum,int RoomNumber,int RoomDay)//������ס�޷�
   { 
       double charge;
       charge=RoomNumber*RoomDay*room[TypeNum].perCharge;
       return charge;
   }

   void Detail(int type)//��ʾ��type��ϸ�ڸ��û�
   {
       System.out.println(room[type].RoomType);
       System.out.println(room[type].RoomDes);
       System.out.println(room[type].perCharge);
   }

   static void menu()//��ʾ�����嵥
   {
       int i;
       for(i=0;i<TotalType;i++)
       {
           System.out.println(i+"."+room[i].RoomType);
       }
   }

   static void Read(String source) throws IOException//���ļ���Ϊargs[0]�ж�ȡ�������ݲ�����������
   {
       room=new Room[10];
       String s;
       int i=0;
       BufferedReader br=new BufferedReader(new FileReader(source));
       TotalType=Integer.parseInt(br.readLine());//������������
       //System.out.println(TotalType);
       while((s=br.readLine())!=null)
       {
            System.out.println(s);
            StringTokenizer st=new StringTokenizer(s,"|");
            try{
                 while(st.hasMoreTokens())
                 {
                     if(i%3==0){room[i/3]=new Room();room[i/3].RoomType=st.nextToken();System.out.println(room[i/3].RoomType);}
                     if(i%3==1){room[(i-1)/3]=new Room();room[(i-1)/3].RoomDes=st.nextToken();System.out.println(room[(i-1)/3].RoomDes);}
                     if(i%3==2){room[(i-2)/3]=new Room();room[(i-2)/3].perCharge=Double.parseDouble(st.nextToken());System.out.println(room[(i-2)/3].perCharge);}
                     i++;
                 }
            }catch(java.lang.NullPointerException e){System.out.println("Something Wrong!");}
       }
       br.close();
   }

   static void Write(int TypeNum,int RoomNumber,int RoomDay,PrintWriter pw)//���û�ס����¼׷��д���ļ���
   {
      pw.println(RoomNumber+" "+room[TypeNum].RoomType+
       " has/have been occupied for "+RoomDay+" day(s).");
   }

   public static void main(String args[]) throws IOException{
      room=new Room[10];
      PrintWriter pw;
      pw=new PrintWriter(new FileWriter(args[1],true));    
      Scanner scan=new Scanner(System.in);
      String ch;
      int typeno=0,roomnum=0,day=0;
      double charge=0;
      Read(args[0]);
      for(;;)
      {
        System.out.println("Do you want to book rooms?(Y/N)");
        ch=scan.next();
        if(ch.equals("Y"))
        {
            System.out.println("Please enter the number of type of room you want to book.");
            menu();
            typeno=scan.nextInt();
            System.out.println("Please enter the number of rooms you want to book.");
            roomnum=scan.nextInt();
            System.out.println("Please enter the days you want to stay in the rooms.");
            day=scan.nextInt();
            charge=RoomCharge(typeno,roomnum,day);
            System.out.println("The total charge is "+charge+" dollars.");
            Write(typeno,roomnum,day,pw);
             
        }
        else if(ch.equals("N"))
        {
            break;
        }
        else
        {
            System.out.println("Please enter Y or N.Other characters will not work.");
        }
   
      
      }
}

}



