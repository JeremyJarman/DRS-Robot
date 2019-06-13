using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO.Ports;



namespace InMoovControl
{
    public partial class Form1 : Form
    {
        public Stopwatch watch { get; set;}

        public static int[] CurrentLPos = new int [10] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        public static int[] CurrentRPos = new int[10] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        public static int[] CurrentHPos = new int[2] {0,0};
        public static int[] HRangeMin = new int[2] {35,15};
        public static int[] HRangeMax = new int[2] {110,85};
        public static string[] HeadNames = new string[2] { "Tilt", "Pan" };
        public static string[] Names = new string[10] {"Flex", "Add","Circ", "Bicep", "Wrist", "Thumb", "Index","Middle", "Ring", "Little"};
        public static int[] StartPos = new int[10] {0,0,90,65,0,0,0,0,0,0};
        public static int[] RangeMin = new int[10] {0,0,70,15,0,0,0,0,0,0};
        public static int[] RangeMax = new int[10] {70,0,110,65,0,170,170,170,170,170};

        //Combine all the servo positions into a single array

        //#35#15#0#0#70#15#0#0#0#0#0#0#0#0#70#15#0#0#0#0#0#0
        //String terminators if we use COBS
        private byte terminator = 00;
        private string tString = string.Empty;



        private void Form1_Load(object sender, EventArgs e)
        {
            serialPort1.Open();
            watch = Stopwatch.StartNew();

        }


        public void UpdateAllPos() {
            var AllPos = new List<int>();

            
            //AllPos.AddRange(CurrentHPos);
            //AllPos.AddRange(CurrentLPos);
            //AllPos.AddRange(CurrentRPos);
            //return (AllPos);
            //string msg = "";
            //for (int i = 0; i < AllPos.Count; i++)
            //{
            //    msg = msg + "#" + AllPos[i];
            //}
            //Console.WriteLine(msg);

            AllPos.Clear();

            AllPos.AddRange(MapTo(CurrentHPos, HRangeMin, HRangeMax));
            AllPos.AddRange(MapTo(CurrentLPos, RangeMin, RangeMax));
            AllPos.AddRange(MapTo(CurrentRPos, RangeMin, RangeMax));

            string msg2 = "";
            for (int i = 0; i < AllPos.Count; i++)
            {
                msg2 = msg2 + "#" + AllPos[i];
            }
            Console.WriteLine(msg2);
            serialPort1.Write(msg2);

        }

        static int Map(int RMin, int RMax, int LimMin,int LimMax, int val)
        {
            int result = LimMin + (val - RMin) * (LimMax - LimMin) / (RMax - RMin);
            return (result);
        }

        public int[] MapTo (int[] ScrollValue, int[] min, int[] max)
        {
            int[] newVal = new int[ScrollValue.Length];

            for (int i = 0; i < newVal.Length; i++)
            {
                newVal[i] = Map(0, 10, min[i], max[i], ScrollValue[i]);
            }

            
            return (newVal); 
        }


        public Form1()
        {
            InitializeComponent();
            
        }

  

        public void WriteToPort()
        {

            string msg = "";
            for (int i = 0; i < Names.Length; i++)
            {
                msg = msg + "#" + CurrentLPos[i];
            }

            byte[] testmsg = new byte[10] {90,80,70,60,50,90,70,60,50,10};

            serialPort1.Write(testmsg,0,5);
            Console.WriteLine("Test message sent");
            //serialPort1.DataReceived += new SerialDataReceivedEventHandler(serialPort_DataReceived);

        }   

        public void WriteToConsole()
        {
            // serialPort1.Write(String.Format(pos));
            if (watch.ElapsedMilliseconds > 15)
            {
                watch = Stopwatch.StartNew();

               // for (int i = 0; i < Names.Length; i++)
               // {
               //     Console.WriteLine(Names[i] + "  " + CurrentLPos[i]);
               // }

                string msg = "Left Side:";
                for (int i = 0; i < Names.Length; i++)
                {
                    msg = msg + "#" + CurrentLPos[i];
                }

                string msg2 = "Right Side:";
                for (int i = 0; i < Names.Length; i++)
                {
                    msg2 = msg2 + "#" + CurrentRPos[i];
                }

                Console.WriteLine(msg);
                Console.WriteLine(msg2);
            }
         }

        public void MapVal(int[] cpos)
        {

        } 

        public void Button1_Click(object sender, EventArgs e)
        {
            // WriteToConsole();
            //WriteToPort();
            UpdateAllPos();
        }


        private void Read_Click(object sender, EventArgs e)
        {
           
        }


        private void Label1_Click(object sender, EventArgs e)
        {

        }


        private void Label2_Click(object sender, EventArgs e)
        {

        }

        private void Label10_Click(object sender, EventArgs e)
        {

        }


        private void LFlex_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[0] = LFlex.Value;

            if (Live.Checked) {
                UpdateAllPos();
            }
        }



        private void LAdd_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[1] = LAdd.Value;
        }

        private void LCirc_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[2] = LCirc.Value;
        }

        private void LBicep_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[3] = LBicep.Value;
        }

        private void LWrist_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[4] = LWrist.Value;
        }

        private void LThumb_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[5] = LThumb.Value;
        }

        private void LIndex_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[6] = LIndex.Value;
        }

        private void LMiddle_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[7] = LMiddle.Value;
        }

        private void LRing_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[8] = LRing.Value;
        }

        private void LLittle_Scroll(object sender, EventArgs e)
        {
            CurrentLPos[9] = LLittle.Value;
        }

    
        private void Live_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void RFlex_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[0] = RFlex.Value;
        }

        private void RAdd_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[1] = RAdd.Value;
        }

        private void RCirc_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[2] = RCirc.Value;
        }

        private void RBicep_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[3] = RBicep.Value;
            if (Live.Checked)
            {
                UpdateAllPos();
            }
        }

        private void RWrist_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[4] = RWrist.Value;
            if (Live.Checked)
            {
                UpdateAllPos();
            }
        }

        private void RThumb_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[5] = RThumb.Value;
            if (Live.Checked)
            {
                UpdateAllPos();
            }
        }

        private void RIndex_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[6] = RIndex.Value;
            if (Live.Checked)
            {
                UpdateAllPos();
            }
        }

        private void RMiddle_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[7] = RMiddle.Value;
            if (Live.Checked)
            {
                UpdateAllPos();
            }
        }

        private void RRing_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[8] = RRing.Value;
            if (Live.Checked)
            {
                UpdateAllPos();
            }
        }

        private void RLittle_Scroll(object sender, EventArgs e)
        {
            CurrentRPos[9] = RLittle.Value;
            if (Live.Checked)
            {
                UpdateAllPos();
            }
        }

        private void Label11_Click(object sender, EventArgs e)
        {

        }

        private void Tilt_Scroll(object sender, EventArgs e)
        {
            CurrentHPos[0] = Tilt.Value;
        }

        private void Pan_Scroll(object sender, EventArgs e)
        {
            CurrentHPos[1] = trackBar1.Value;
        }
    }
}
