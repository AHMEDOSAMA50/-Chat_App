using System;
using System.Data;
using System.Drawing;
using System.Windows.Forms;
using System.Data.SQLite;
using System.IO;



namespace ChatApp
{
    public partial class signup : Form
    {


        public signup()
        {
            InitializeComponent();
            //image

        }
        SQLiteConnection conn = new SQLiteConnection("Data Source=ChatDataBase.db;Version=3;");
        SQLiteCommand cmd = new SQLiteCommand();
        SQLiteDataAdapter da = new SQLiteDataAdapter();


        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            this.Hide();
            login login = new login();
            login.Show();
        }



        private void btnSignup_Click(object sender, EventArgs e)
        {

            if (txt_userSignup.Text.Trim() == ""
                 && txt_passwordSignup.Text.Trim() == ""
                 && txt_repasswordSignup.Text.Trim() == ""
                 && txt_phoneSignup.Text.Trim() == ""
                 && txt_emailSignup.Text.Trim() == "")

            {
                MessageBox.Show("Username , Password ,Phone and Email fields are empty ", "Registration Failed", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (txt_passwordSignup.Text == txt_repasswordSignup.Text)
            {
                try
                {
                    LoadImage(lbl_fileName.Text, picbox_singup.Image);
                    SQLiteConnection conn = new SQLiteConnection("Data Source=ChatDataBase.db;Version=3;");
                    conn.Open();
                    string sqlip = " update Users set username = '" + txt_userSignup.Text + "', password = '" + txt_passwordSignup.Text + "',phone='" + txt_phoneSignup.Text + "',email='" + txt_emailSignup.Text + "'WHERE filename='" + lbl_fileName.Text + "';";
                    string query = "INSERT INTO Users(username,password,phone,email)VALUES ('" + txt_userSignup.Text + "','" + txt_passwordSignup.Text + "','" + txt_phoneSignup.Text + "','" + txt_emailSignup.Text + "' )";
                    SQLiteCommand cmd = new SQLiteCommand(sqlip, conn);




                    cmd.ExecuteNonQuery();
                    conn.Close();


                    //pr.label_username.Text = 

                    txt_userSignup.Text = "";
                    txt_passwordSignup.Text = "";
                    txt_repasswordSignup.Text = "";
                    txt_phoneSignup.Text = "";
                    txt_emailSignup.Text = "";
                }
                catch (Exception q)
                {
                    q.ToString();
                }


                MessageBox.Show("Your Account has been Successfully Created", "Registration Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Passwords does not match, Please Re-enter", "Registration Failed", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txt_passwordSignup.Text = "";
                txt_repasswordSignup.Text = "";
                txt_passwordSignup.Focus();


            }

        }

        private void label14_Click(object sender, EventArgs e)
        {
            new signup().Show();
            this.Hide();
        }

        public byte[] ImageToByte(Image image, System.Drawing.Imaging.ImageFormat format)
        {
            using (MemoryStream ms = new MemoryStream())
            {
                // Convert Image to byte[]
                image.Save(ms, format);
                byte[] imageBytes = ms.ToArray();
                return imageBytes;
            }
        }
        //public Image Base64ToImage(string base64String)
        public Image ByteToImage(byte[] imageBytes)
        {
            // Convert byte[] to Image
            MemoryStream ms = new MemoryStream(imageBytes, 0, imageBytes.Length);
            ms.Write(imageBytes, 0, imageBytes.Length);
            Image image = new Bitmap(ms);
            return image;
        }
        /***************** SQLite **************************/
        void SaveImage(byte[] imagen)
        {
            string conStringDatosUsuarios = @" Data Source=ChatDataBase.db;Version=3; ";
            SQLiteConnection con = new SQLiteConnection(conStringDatosUsuarios);
            SQLiteCommand cmd = con.CreateCommand();
            cmd.CommandText = String.Format("INSERT INTO Users (img,filename) VALUES (@0,'" + lbl_fileName.Text + "');");
            SQLiteParameter param = new SQLiteParameter("@0", System.Data.DbType.Binary);
            param.Value = imagen;
            cmd.Parameters.Add(param);
            con.Open();

            try
            {
                cmd.ExecuteNonQuery();
            }
            catch (Exception exc1)
            {
                MessageBox.Show(exc1.Message);
            }
            con.Close();
        }
        public void LoadImage(string p, Image i)
        {
            string path = p;
            string query = "SELECT img FROM Users WHERE filename='" + path + "';";
            string conString = @" Data Source=ChatDataBase.db;Version=3; ";
            SQLiteConnection con = new SQLiteConnection(conString);
            SQLiteCommand cmd = new SQLiteCommand(query, con);
            con.Open();
            try
            {
                IDataReader rdr = cmd.ExecuteReader();
                try
                {
                    while (rdr.Read())
                    {
                        byte[] a = (System.Byte[])rdr[0];
                        i = ByteToImage(a);
                    }
                }
                catch (Exception exc) { MessageBox.Show(exc.Message); }
            }
            catch (Exception ex) { MessageBox.Show(ex.Message); }
            con.Close();
        }



        private void btn_open_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog() { Filter = "JPEG|*.jpg", ValidateNames = true, Multiselect = false })
            {
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    lbl_fileName.Text = openFileDialog.FileName;
                    picbox_singup.Image = Image.FromFile(openFileDialog.FileName);


                }
            }
        }
        private void btn_load_Click(object sender, EventArgs e)
        {

            Image photo = new Bitmap(lbl_fileName.Text);
            byte[] pic = ImageToByte(photo, System.Drawing.Imaging.ImageFormat.Jpeg);
            SaveImage(pic);
            // LoadImage();

        }
    }
}