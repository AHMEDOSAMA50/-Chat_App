using System;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;
using ChatApplication;


namespace ChatApp
{
    public partial class home : Form
    {
        TcpClient client;
        byte[] buffer = new byte[4096];

        public home()
        {
            InitializeComponent();

            client = new TcpClient();

        }
        protected override void OnShown(EventArgs e)   //when the client has been sown we are goin to connect to the server 
                                                       //not before .because begin invoke can't be called untill the window handle has been created  
        {

            base.OnShown(e);
            client.Connect("192.168.1.90", 54000);
            client.GetStream().BeginRead(buffer, 0, buffer.Length, server_MessageReceived, null);
        }

        private void server_MessageReceived(IAsyncResult ar)
        {
            if (ar.IsCompleted)
            {
                //receive message
                var bytesIn = client.GetStream().EndRead(ar);
                if (bytesIn > 0)
                {
                    var tmp = new byte[bytesIn];
                    Array.Copy(buffer, 0, tmp, 0, bytesIn);
                    var str = Encoding.ASCII.GetString(tmp);
                    //make this an actual delegate read docs
                    BeginInvoke((Action)(() => {
                        listBox1.Items.Add(str);
                        listBox1.Items.Add("");
                    }));
                }
                Array.Clear(buffer, 0, buffer.Length);
                client.GetStream().BeginRead(buffer, 0, buffer.Length, server_MessageReceived, null);


            }
        }

        private void Home_Load(object sender, EventArgs e)
        {

        }
        private void Button7_Click(object sender, EventArgs e)
        {
            var msg = Encoding.ASCII.GetBytes(textBox2.Text);
            client.GetStream().Write(msg, 0, msg.Length);
            textBox2.Text = "";
            textBox2.Focus();

        }

        private void textBox2_MouseClick(object sender, MouseEventArgs e)
        {
            textBox2.Text = "";

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Button_add(object sender, EventArgs e)
        {
            ////listView1.Items.Add(txtboxusername.Text);
            //listView1.Items[listView1.Items.Count - 1].SubItems.Add(txtboxusername.Text);
            //listView1.Items[listView1.Items.Count - 1].SubItems.Add(txtboxmobile.Text);  
        }

        private void label3_Click(object sender, EventArgs e)
        {


        }

        private void home_Load_1(object sender, EventArgs e)
        {
            ////set LV properties
            //listView1.View = View.Details;
            //listView1.FullRowSelect = true;
        }

        private void listView1_MouseClick(object sender, MouseEventArgs e)
        {
            string username = listView1.SelectedItems[0].SubItems[0].Text;
            string mobilenum = listView1.SelectedItems[0].SubItems[1].Text;

            txtboxmobile.Text = username;
            txtboxusername.Text = mobilenum;
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {
            this.Hide();
            story s =new story();
            s.Show();

        }
    }

}
