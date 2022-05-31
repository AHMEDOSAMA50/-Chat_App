using System;
using System.Windows.Forms;
using ChatApplication;
using System.Data.SQLite;
using System.IO;
using System.Drawing;

namespace ChatApp
{
    public partial class login : Form
    {

        string connstring = @"Data Source=ChatDataBase.db;Version=3;";

        public login()
        {
            InitializeComponent();
        }
        
        private void textBox1_MouseClick(object sender, MouseEventArgs e)
        {
            //if (txt_user.Text == "username")
            //{
            //    txt_user.Text = "";
            //}
        }

        private void textBox3_MouseClick(object sender, MouseEventArgs e)
        {
            if (txt_password.Text == "password")
            {
                txt_user.Text = "";
            }

        }

        private void label5_MouseClick(object sender, MouseEventArgs e)
        {
            if (txt_user.Text == "")
            {
                txt_user.Text = "username";
            }
            if (txt_password.Text == "")
            {
                txt_password.Text = "password";
            }
            DialogResult d;
            d = MessageBox.Show("are you sure you want to continue without signing in? this will stop synchronizing your settings and won't customize any settings.", "Are you sure?", MessageBoxButtons.YesNo, MessageBoxIcon.Information);
            if (d == DialogResult.Yes)
            {
                this.Hide();
                home home = new home();
                home.Show();
            }
            else
            {
                return;

            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                btn_Login.Enabled = true;
            }
            else
            {
                btn_Login.Enabled = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            signup signup = new signup();
            signup.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            {
                if (txt_user.Text.Trim() == "" && txt_password.Text.Trim() == "")
                {
                    MessageBox.Show("Empty Fields", "Error");
                }
                else
                {

                    try
                    {
                        string query = "SELECT id,username,password,phone ,email,Bio,img,filename FROM Users  WHERE username= '" + txt_user.Text + "' and password= '" + txt_password.Text + "'";

                        SQLiteConnection conn = new SQLiteConnection(connstring);
                        conn.Open();
                        SQLiteCommand cmd = new SQLiteCommand(query, conn);
                        SQLiteDataAdapter da = new SQLiteDataAdapter(cmd);

                        SQLiteDataReader dr = cmd.ExecuteReader();
                        if (dr.Read() == true)
                        {
                            home hm = new home();
                            profile pr = new profile();
                            signup signup = new signup();
                            story story = new story();
                            //The Form which will appear after loggin in
                            MessageBox.Show("You are Logged in", "Login Successful");
                            pr.label_username.Text = dr[1].ToString();
                            pr.label_password.Text = dr[2].ToString();
                            pr.label_phone.Text = dr[3].ToString();
                            pr.label_email.Text = dr[4].ToString();
                            pr.label_Bio.Text = dr[5].ToString();
                            string path = dr[7].ToString();
                            story.name_label.Text = dr[1].ToString();
             
                            pr.pr_pictureBox.Image = Image.FromFile(path);
                            signup.LoadImage(path, pr.pr_pictureBox.Image);

                            hm.hm_pictureBox.Image = Image.FromFile(path);
                            signup.LoadImage(path, hm.hm_pictureBox.Image);

                            story.pic_box_status.Image = Image.FromFile(path);
                            signup.LoadImage(path, story.pic_box_status.Image);

                            pr.ShowDialog();
                            hm.ShowDialog();

                            this.Hide();
                            hm.Show();
                            pr.ShowDialog();
         
                        }
                        else
                        {
                            MessageBox.Show("Invalid Username or Password, Please Try Again", "Login Failed", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            txt_user.Text = "";
                            txt_password.Text = "";
                            txt_user.Focus();
                        }

                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message);


                    }


                }
            }


            }

        private void txt_user_TextChanged(object sender, EventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
