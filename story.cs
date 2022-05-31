using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ChatApplication
{
    public partial class story : Form
    {
        public story()
        {
            InitializeComponent();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog() { Filter = "JPEG|*.jpg", ValidateNames = true, Multiselect = false })
            {
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    pictureBox3.Image = Image.FromFile(openFileDialog.FileName);
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label1.Text = textBox1.Text;
            textBox1.Text = "";

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            //this.textBox1.Text = richTextBox1.Text; 
        }

        private void name_label_Click(object sender, EventArgs e)
        {
            MessageBox.Show("don't click me again!!");
        }
    }
}
