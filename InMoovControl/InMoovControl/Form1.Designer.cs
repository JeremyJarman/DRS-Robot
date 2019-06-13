namespace InMoovControl
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.LFlex = new System.Windows.Forms.TrackBar();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.RFlex = new System.Windows.Forms.TrackBar();
            this.RAdd = new System.Windows.Forms.TrackBar();
            this.label2 = new System.Windows.Forms.Label();
            this.LAdd = new System.Windows.Forms.TrackBar();
            this.RCirc = new System.Windows.Forms.TrackBar();
            this.label3 = new System.Windows.Forms.Label();
            this.LCirc = new System.Windows.Forms.TrackBar();
            this.RBicep = new System.Windows.Forms.TrackBar();
            this.label4 = new System.Windows.Forms.Label();
            this.LBicep = new System.Windows.Forms.TrackBar();
            this.RWrist = new System.Windows.Forms.TrackBar();
            this.label5 = new System.Windows.Forms.Label();
            this.LWrist = new System.Windows.Forms.TrackBar();
            this.label6 = new System.Windows.Forms.Label();
            this.LLittle = new System.Windows.Forms.TrackBar();
            this.RRing = new System.Windows.Forms.TrackBar();
            this.label7 = new System.Windows.Forms.Label();
            this.LRing = new System.Windows.Forms.TrackBar();
            this.RMiddle = new System.Windows.Forms.TrackBar();
            this.label8 = new System.Windows.Forms.Label();
            this.LMiddle = new System.Windows.Forms.TrackBar();
            this.RIndex = new System.Windows.Forms.TrackBar();
            this.label9 = new System.Windows.Forms.Label();
            this.LIndex = new System.Windows.Forms.TrackBar();
            this.RThumb = new System.Windows.Forms.TrackBar();
            this.label10 = new System.Windows.Forms.Label();
            this.LThumb = new System.Windows.Forms.TrackBar();
            this.Live = new System.Windows.Forms.CheckBox();
            this.Read = new System.Windows.Forms.Button();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.Tilt = new System.Windows.Forms.TrackBar();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.RLittle = new System.Windows.Forms.TrackBar();
            ((System.ComponentModel.ISupportInitialize)(this.LFlex)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RFlex)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RAdd)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LAdd)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RCirc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LCirc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RBicep)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LBicep)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RWrist)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LWrist)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LLittle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RRing)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LRing)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RMiddle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LMiddle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RIndex)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LIndex)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RThumb)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LThumb)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Tilt)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RLittle)).BeginInit();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.BaudRate = 115200;
            this.serialPort1.PortName = "COM12";
            // 
            // LFlex
            // 
            this.LFlex.Cursor = System.Windows.Forms.Cursors.Default;
            this.LFlex.Location = new System.Drawing.Point(273, 361);
            this.LFlex.Name = "LFlex";
            this.LFlex.Size = new System.Drawing.Size(118, 45);
            this.LFlex.TabIndex = 0;
            this.LFlex.Scroll += new System.EventHandler(this.LFlex_Scroll);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(396, 636);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "Send";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(165, 361);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "FLEXION";
            this.label1.Click += new System.EventHandler(this.Label1_Click);
            // 
            // RFlex
            // 
            this.RFlex.Location = new System.Drawing.Point(7, 361);
            this.RFlex.Name = "RFlex";
            this.RFlex.Size = new System.Drawing.Size(118, 45);
            this.RFlex.TabIndex = 3;
            this.RFlex.Scroll += new System.EventHandler(this.RFlex_Scroll);
            // 
            // RAdd
            // 
            this.RAdd.Location = new System.Drawing.Point(7, 412);
            this.RAdd.Name = "RAdd";
            this.RAdd.Size = new System.Drawing.Size(118, 45);
            this.RAdd.TabIndex = 6;
            this.RAdd.Scroll += new System.EventHandler(this.RAdd_Scroll);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(155, 412);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(71, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "ADDUCTION";
            this.label2.Click += new System.EventHandler(this.Label2_Click);
            // 
            // LAdd
            // 
            this.LAdd.Location = new System.Drawing.Point(273, 412);
            this.LAdd.Name = "LAdd";
            this.LAdd.Size = new System.Drawing.Size(118, 45);
            this.LAdd.TabIndex = 4;
            this.LAdd.Scroll += new System.EventHandler(this.LAdd_Scroll);
            // 
            // RCirc
            // 
            this.RCirc.Location = new System.Drawing.Point(7, 463);
            this.RCirc.Name = "RCirc";
            this.RCirc.Size = new System.Drawing.Size(118, 45);
            this.RCirc.TabIndex = 9;
            this.RCirc.Scroll += new System.EventHandler(this.RCirc_Scroll);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(140, 463);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(98, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "CIRCUMDUCTION";
            // 
            // LCirc
            // 
            this.LCirc.Location = new System.Drawing.Point(273, 463);
            this.LCirc.Name = "LCirc";
            this.LCirc.Size = new System.Drawing.Size(118, 45);
            this.LCirc.TabIndex = 7;
            this.LCirc.Scroll += new System.EventHandler(this.LCirc_Scroll);
            // 
            // RBicep
            // 
            this.RBicep.Location = new System.Drawing.Point(7, 514);
            this.RBicep.Name = "RBicep";
            this.RBicep.Size = new System.Drawing.Size(118, 45);
            this.RBicep.TabIndex = 12;
            this.RBicep.Scroll += new System.EventHandler(this.RBicep_Scroll);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(170, 514);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(38, 13);
            this.label4.TabIndex = 11;
            this.label4.Text = "BICEP";
            // 
            // LBicep
            // 
            this.LBicep.Location = new System.Drawing.Point(273, 514);
            this.LBicep.Name = "LBicep";
            this.LBicep.Size = new System.Drawing.Size(118, 45);
            this.LBicep.TabIndex = 10;
            this.LBicep.Scroll += new System.EventHandler(this.LBicep_Scroll);
            // 
            // RWrist
            // 
            this.RWrist.Location = new System.Drawing.Point(7, 565);
            this.RWrist.Name = "RWrist";
            this.RWrist.Size = new System.Drawing.Size(118, 45);
            this.RWrist.TabIndex = 15;
            this.RWrist.Scroll += new System.EventHandler(this.RWrist_Scroll);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(165, 565);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(43, 13);
            this.label5.TabIndex = 14;
            this.label5.Text = "WRIST";
            // 
            // LWrist
            // 
            this.LWrist.Location = new System.Drawing.Point(273, 565);
            this.LWrist.Name = "LWrist";
            this.LWrist.Size = new System.Drawing.Size(118, 45);
            this.LWrist.TabIndex = 13;
            this.LWrist.Scroll += new System.EventHandler(this.LWrist_Scroll);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(668, 565);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(43, 13);
            this.label6.TabIndex = 29;
            this.label6.Text = "LITTLE";
            // 
            // LLittle
            // 
            this.LLittle.Location = new System.Drawing.Point(763, 565);
            this.LLittle.Name = "LLittle";
            this.LLittle.Size = new System.Drawing.Size(118, 45);
            this.LLittle.TabIndex = 28;
            this.LLittle.Scroll += new System.EventHandler(this.LLittle_Scroll);
            // 
            // RRing
            // 
            this.RRing.Location = new System.Drawing.Point(497, 514);
            this.RRing.Name = "RRing";
            this.RRing.Size = new System.Drawing.Size(118, 45);
            this.RRing.TabIndex = 27;
            this.RRing.Scroll += new System.EventHandler(this.RRing_Scroll);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(672, 514);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(34, 13);
            this.label7.TabIndex = 26;
            this.label7.Text = "RING";
            // 
            // LRing
            // 
            this.LRing.Location = new System.Drawing.Point(763, 514);
            this.LRing.Name = "LRing";
            this.LRing.Size = new System.Drawing.Size(118, 45);
            this.LRing.TabIndex = 25;
            this.LRing.Scroll += new System.EventHandler(this.LRing_Scroll);
            // 
            // RMiddle
            // 
            this.RMiddle.Location = new System.Drawing.Point(497, 463);
            this.RMiddle.Name = "RMiddle";
            this.RMiddle.Size = new System.Drawing.Size(118, 45);
            this.RMiddle.TabIndex = 24;
            this.RMiddle.Scroll += new System.EventHandler(this.RMiddle_Scroll);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(667, 463);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(48, 13);
            this.label8.TabIndex = 23;
            this.label8.Text = "MIDDLE";
            // 
            // LMiddle
            // 
            this.LMiddle.Location = new System.Drawing.Point(763, 463);
            this.LMiddle.Name = "LMiddle";
            this.LMiddle.Size = new System.Drawing.Size(118, 45);
            this.LMiddle.TabIndex = 22;
            this.LMiddle.Scroll += new System.EventHandler(this.LMiddle_Scroll);
            // 
            // RIndex
            // 
            this.RIndex.Location = new System.Drawing.Point(497, 412);
            this.RIndex.Name = "RIndex";
            this.RIndex.Size = new System.Drawing.Size(118, 45);
            this.RIndex.TabIndex = 21;
            this.RIndex.Scroll += new System.EventHandler(this.RIndex_Scroll);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(668, 412);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(40, 13);
            this.label9.TabIndex = 20;
            this.label9.Text = "INDEX";
            // 
            // LIndex
            // 
            this.LIndex.Location = new System.Drawing.Point(763, 412);
            this.LIndex.Name = "LIndex";
            this.LIndex.Size = new System.Drawing.Size(118, 45);
            this.LIndex.TabIndex = 19;
            this.LIndex.Scroll += new System.EventHandler(this.LIndex_Scroll);
            // 
            // RThumb
            // 
            this.RThumb.Location = new System.Drawing.Point(497, 361);
            this.RThumb.Name = "RThumb";
            this.RThumb.Size = new System.Drawing.Size(118, 45);
            this.RThumb.TabIndex = 18;
            this.RThumb.Scroll += new System.EventHandler(this.RThumb_Scroll);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(667, 361);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(46, 13);
            this.label10.TabIndex = 17;
            this.label10.Text = "THUMB";
            this.label10.Click += new System.EventHandler(this.Label10_Click);
            // 
            // LThumb
            // 
            this.LThumb.Location = new System.Drawing.Point(763, 361);
            this.LThumb.Name = "LThumb";
            this.LThumb.Size = new System.Drawing.Size(118, 45);
            this.LThumb.TabIndex = 16;
            this.LThumb.Scroll += new System.EventHandler(this.LThumb_Scroll);
            // 
            // Live
            // 
            this.Live.AutoSize = true;
            this.Live.Location = new System.Drawing.Point(779, 642);
            this.Live.Name = "Live";
            this.Live.Size = new System.Drawing.Size(46, 17);
            this.Live.TabIndex = 31;
            this.Live.Text = "Live";
            this.Live.UseVisualStyleBackColor = true;
            this.Live.CheckedChanged += new System.EventHandler(this.Live_CheckedChanged);
            // 
            // Read
            // 
            this.Read.Location = new System.Drawing.Point(396, 665);
            this.Read.Name = "Read";
            this.Read.Size = new System.Drawing.Size(75, 23);
            this.Read.TabIndex = 32;
            this.Read.Text = "Read";
            this.Read.UseVisualStyleBackColor = true;
            this.Read.Click += new System.EventHandler(this.Read_Click);
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(338, 266);
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(195, 45);
            this.trackBar1.TabIndex = 33;
            // 
            // Tilt
            // 
            this.Tilt.Location = new System.Drawing.Point(290, 29);
            this.Tilt.Name = "Tilt";
            this.Tilt.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.Tilt.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Tilt.Size = new System.Drawing.Size(45, 228);
            this.Tilt.TabIndex = 34;
            this.Tilt.Value = 10;
            this.Tilt.Scroll += new System.EventHandler(this.Tilt_Scroll);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::InMoovControl.Properties.Resources.inmoov_head2;
            this.pictureBox1.Location = new System.Drawing.Point(338, 29);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(195, 228);
            this.pictureBox1.TabIndex = 35;
            this.pictureBox1.TabStop = false;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(427, 298);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(26, 13);
            this.label11.TabIndex = 36;
            this.label11.Text = "Pan";
            this.label11.Click += new System.EventHandler(this.Label11_Click);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(258, 142);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(21, 13);
            this.label12.TabIndex = 37;
            this.label12.Text = "Tilt";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(12, 636);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 38;
            this.button2.Text = "Save";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // RLittle
            // 
            this.RLittle.Location = new System.Drawing.Point(497, 565);
            this.RLittle.Name = "RLittle";
            this.RLittle.Size = new System.Drawing.Size(118, 45);
            this.RLittle.TabIndex = 30;
            this.RLittle.Scroll += new System.EventHandler(this.RLittle_Scroll);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(912, 749);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.Tilt);
            this.Controls.Add(this.trackBar1);
            this.Controls.Add(this.Read);
            this.Controls.Add(this.Live);
            this.Controls.Add(this.RLittle);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.LLittle);
            this.Controls.Add(this.RRing);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.LRing);
            this.Controls.Add(this.RMiddle);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.LMiddle);
            this.Controls.Add(this.RIndex);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.LIndex);
            this.Controls.Add(this.RThumb);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.LThumb);
            this.Controls.Add(this.RWrist);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.LWrist);
            this.Controls.Add(this.RBicep);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.LBicep);
            this.Controls.Add(this.RCirc);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.LCirc);
            this.Controls.Add(this.RAdd);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.LAdd);
            this.Controls.Add(this.RFlex);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.LFlex);
            this.Name = "Form1";
            this.Text = "l";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.LFlex)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RFlex)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RAdd)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LAdd)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RCirc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LCirc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RBicep)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LBicep)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RWrist)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LWrist)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LLittle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RRing)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LRing)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RMiddle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LMiddle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RIndex)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LIndex)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RThumb)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LThumb)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Tilt)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RLittle)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.TrackBar LFlex;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TrackBar RFlex;
        private System.Windows.Forms.TrackBar RAdd;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TrackBar LAdd;
        private System.Windows.Forms.TrackBar RCirc;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TrackBar LCirc;
        private System.Windows.Forms.TrackBar RBicep;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TrackBar LBicep;
        private System.Windows.Forms.TrackBar RWrist;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TrackBar LWrist;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TrackBar LLittle;
        private System.Windows.Forms.TrackBar RRing;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TrackBar LRing;
        private System.Windows.Forms.TrackBar RMiddle;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TrackBar LMiddle;
        private System.Windows.Forms.TrackBar RIndex;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TrackBar LIndex;
        private System.Windows.Forms.TrackBar RThumb;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TrackBar LThumb;
        private System.Windows.Forms.CheckBox Live;
        private System.Windows.Forms.Button Read;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.TrackBar Tilt;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TrackBar RLittle;
    }
}

