using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ChatApp;

namespace ChatApplication
{
    public partial class profile : Form
    {
        login login = new login();
        public profile()
        {
            InitializeComponent();
        }
        private void profile_Load(object sender, EventArgs e)
        {  
           
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            home home = new home();
            home.Show();
        }
    }
}

//