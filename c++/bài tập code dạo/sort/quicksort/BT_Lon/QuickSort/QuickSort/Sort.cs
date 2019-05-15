using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using System.IO;

namespace QuickSort
{
    public partial class Sort : Form
    {
        public Sort()
        {
            InitializeComponent();
            //Tải code của thuật toán Quick Sort vào Cửa sổ xem code
            lst_Code.Items.Add("void QuickSort(int a[], int left, int right)");
            lst_Code.Items.Add("     {");
            lst_Code.Items.Add("            int i, j, x;");
            lst_Code.Items.Add("            x = a[(left + right) / 2]; ");
            lst_Code.Items.Add("            i = left; j = right;");
            lst_Code.Items.Add("               do");
            lst_Code.Items.Add("                  {");
            lst_Code.Items.Add("                   while(a[i] < x) i++;");
            lst_Code.Items.Add("                   while(a[j] > x) j--;");
            lst_Code.Items.Add("                       if(i <= j)");
            lst_Code.Items.Add("                         { ");
            lst_Code.Items.Add("                           Swap(a[i], a[j]);");
            lst_Code.Items.Add("                           i++ ; j--;");
            lst_Code.Items.Add("                         }");
            lst_Code.Items.Add("                   }");
            lst_Code.Items.Add("               while(i <= j);");
            lst_Code.Items.Add("               if(left < j)");
            lst_Code.Items.Add("                   QuickSort(a, left, j);");
            lst_Code.Items.Add("               if(i < right)");
            lst_Code.Items.Add("                   QuickSort(a, i, right);");
            lst_Code.Items.Add("      }");

        }

        private void QuickSort_Load(object sender, EventArgs e)
        {
            rad_quicksort.Checked = true;
        }

        #region Khai báo các biến toàn cục
        TextBox[] Node;
        int[] a;
        int Spt = 0;
        Label[] Chi_so;
        int Toc_do;
        int i, Kthuoc_Code = 10;
        Boolean Da_tao_mang, KT_tam_dung = false; //Biến kiểm tra đã tạo mảng và kiểm tra tạm dừng
        //Biến kiểm tra sắp xếp 1 lần hay từng bước
        Boolean Sap_xep_tung_buoc;

        #endregion
        #region Khai báo các biến định dạng node
        int Khoang_cach;//khoảng cách 2 node liên tiếp
        int Canh_le;//canh lề node
        int Kich_thuoc; // kích thước node
        int Co_chu; //kích thước chữ
        #endregion Khai báo các biến định dạng node
        #region CÁC HÀM DI CHUYỂN NODE
        // Hàm swap 2 node có thể hiện
        public void Hoan_Vi_Node(Control t1, Control t2)
        {
            Application.DoEvents();

            this.Invoke((MethodInvoker)delegate
            {
                Point p1 = t1.Location; //lưu vị trí ban đầu của t1
                Point p2 = t2.Location; //lưu vị trí ban đầu của t2
                if (p1 != p2)
                {
                    // t1 lên, t2 xuống
                    while ((t1.Location.Y > p1.Y - (Kich_thuoc + 5)) || (t2.Location.Y < p2.Y + (Kich_thuoc + 5)))
                    {
                        Application.DoEvents();
                        t1.Top -= 1;
                        t2.Top += 1;
                        Tre(Toc_do);

                    }
                    // t1 dịch phải, t2 dịch trái
                    if (t1.Location.X < t2.Location.X)
                    {

                        while ((t1.Location.X < p2.X) || (t2.Location.X > p1.X))
                        {
                            Application.DoEvents();
                            t1.Left += 1;
                            t2.Left -= 1;
                            Tre(Toc_do);


                        }

                    }
                    // t1 dịch trái, t2 dịch phải
                    else
                    {

                        while ((t1.Location.X > p2.X) || (t2.Location.X < p1.X))
                        {
                            Application.DoEvents();
                            t1.Left -= 1;
                            t2.Left += 1;
                            Tre(Toc_do);

                        }

                    }
                    // t1 xuống, t2 lên
                    while ((t1.Location.Y < p2.Y) || (t2.Location.Y > p1.Y))
                    {
                        Application.DoEvents();
                        t1.Top += 1;
                        t2.Top -= 1;
                        Tre(Toc_do);

                    }
                    t1.Refresh();
                    t2.Refresh();
                }
            });

        }
        // t dịch chuyển sang Phải Step Node
        public void Node_qua_phai(Control t, int Step)
        {
            Application.DoEvents();

            this.Invoke((MethodInvoker)delegate
            {
                int Loop_Count = ((Kich_thuoc + Khoang_cach)) * Step; //Số lần dịch chuyển
                {
                    while (Loop_Count > 0)
                    {
                        Application.DoEvents();
                        t.Left += 1;
                        Tre(Toc_do);
                        Loop_Count--;
                    }
                }
                t.Refresh();
            });
        }
        // t dịch chuyển sang trai Step Node
        public void Node_qua_trai(Control t, int Step)
        {
            Application.DoEvents();
            this.Invoke((MethodInvoker)delegate
            {
                int Loop_Count = ((Kich_thuoc + Khoang_cach)) * Step; //Số lần dịch chuyển
                while (Loop_Count > 0)
                {
                    Application.DoEvents();
                    t.Left -= 1;
                    Tre(Toc_do);
                    Loop_Count--;
                }
                t.Refresh();
            });
        }
        // t dịch chuyển lên với quãng đường S
        public void Node_di_len(Control t, int S)
        {
            Application.DoEvents();
            this.Invoke((MethodInvoker)delegate
            {
                int loop_Count = S;
                //t xuống
                while (loop_Count > 0)
                {
                    Application.DoEvents();
                    t.Top -= 1;
                    Tre(Toc_do);
                    loop_Count--;
                }
                t.Refresh();
            });
        }
        // t dịch chuyển xuống với quãng đường S
        public void Node_di_xuong(Control t, int S)
        {
            Application.DoEvents();
            this.Invoke((MethodInvoker)delegate
            {
                int loop_Count = S;
                // t lên
                while (loop_Count > 0)
                {
                    Application.DoEvents();
                    t.Top += 1;
                    Tre(Toc_do);
                    loop_Count--;
                }
                t.Refresh();
            });
        }
        // Dịch chuyển 1 Node về vị trí Node[i]
        public void Den_vtri_node(Control t, int i)
        {
            Point p1 = t.Location; // lưu lại vị trí của t
            Point p2 = new Point(Canh_le + (Kich_thuoc + Khoang_cach) * i, 250);//vị trí của Node i
            Application.DoEvents();
            this.Invoke((MethodInvoker)delegate
            {
                // Di chuyển nút lên hoặc xuống nữa đường
                if (p1.Y < p2.Y)
                {
                    while (t.Location.Y < p2.Y - ((p2.Y - p1.Y) / 2))
                    {
                        Application.DoEvents();
                        t.Top += 1;
                        t.Refresh();
                        Tre(Toc_do);

                    }
                }
                else
                {
                    while (t.Location.Y > p2.Y + ((p1.Y - p2.Y) / 2))
                    {
                        Application.DoEvents();
                        t.Top -= 1;
                        t.Refresh();
                        Tre(Toc_do);

                    }
                }
                // Di chuyển nút qua phải hoặc trái
                if (p1.X < p2.X)
                {
                    while (t.Location.X < p2.X)
                    {
                        Application.DoEvents();
                        t.Left += 1;
                        t.Refresh();
                        Tre(Toc_do);
                    }
                }
                else
                {
                    while (t.Location.X > p2.X)
                    {
                        Application.DoEvents();
                        t.Left -= 1;
                        t.Refresh();
                        Tre(Toc_do);
                    }
                }
                // Tiếp tục di chuyển nút lên hoặc xuống nữa đường còn lại
                if (p1.Y < p2.Y)
                {
                    while (t.Location.Y < p2.Y)
                    {
                        Application.DoEvents();
                        t.Top += 1;
                        t.Refresh();
                        Tre(Toc_do);

                    }
                }
                else
                {
                    while (t.Location.Y > p2.Y)
                    {
                        Application.DoEvents();
                        t.Top -= 1;
                        t.Refresh();
                        Tre(Toc_do);
                    }
                }
            });
        }
        // Dịch chuyển 1 Node về vị trí bằng với X của Node[i]
        public void Den_tdo_x_node(Control t, int i)
        {
            Point p1 = t.Location; // lưu lại vị trí của t
            Point p2 = new Point(Canh_le + (Kich_thuoc + Khoang_cach) * i, 250);//vị trí của Node i
            Application.DoEvents();
            this.Invoke((MethodInvoker)delegate
            {
                // Di chuyển nút qua phải hoặc trái
                if (p1.X < p2.X)
                {
                    while (t.Location.X < p2.X)
                    {
                        Application.DoEvents();
                        t.Left += 1;
                        t.Refresh();
                        Tre(Toc_do);
                    }
                }
                else
                {
                    while (t.Location.X > p2.X)
                    {
                        Application.DoEvents();
                        t.Left -= 1;
                        t.Refresh();
                        Tre(Toc_do);
                    }
                }

            });
        }
        #endregion
        #region CÁC HÀM KHÁC
        //Hàm ngủ
        public void SleepP(int milisecond)
        {
            int i;
            for (i = 0; i < milisecond; i++)
            {
                Application.DoEvents();
                Thread.Sleep(5);
            }
            Application.DoEvents();
        }
        //Hàm Trễ
        public void Tre(int milisecond)
        {
            //Nếu tốc độ max thì ko sleep
            if (Trb_Toc_do.Value == Trb_Toc_do.Maximum)
            {
                Application.DoEvents();
                return;
            }

            SleepP(milisecond);
        }
        // Hàm hoán vị 2 node mà không thể hiện
        public void Hoan_Tri_Node(int t1, int t2)
        {
            TextBox Temp = Node[t1];
            Node[t1] = Node[t2];
            Node[t2] = Temp;
        }
        // Hàm hoán vị 2 giá trị
        public void Hoan_vi(ref int i, ref int j)
        {
            int Temp = i;
            i = j;
            j = Temp;

        }

        //Sắp xếp hoàn thành
        public void Hoan_thanh()
        {
            for (i = 0; i < Spt; i++)
            {
                Dat_mau_node(Node[i], Color.LawnGreen, Color.Black);
            }
            //Ẩn các index

            Mui_ten_xanh_xuong_1.Visible = false;
            Mui_ten_xanh_xuong_2.Visible = false;
            Mui_ten_xanh_len_1.Visible = false;
            Mui_ten_xanh_len_2.Visible = false;
            Mui_ten_do_len.Visible = false;
            //
            lbl_status_02.Visible = true;
            lbl_status_02.Text = "Đã sắp xếp xong!";
            btn_Ngaunhien.Enabled = false;
            btn_Nhap.Enabled = false;
            btn_Dung.Enabled = false;
            btn_Chayhet.Enabled = false;
            btn_Ketiep.Enabled = true;
            //Thiết lập các nút nhập liệu
            rad_quicksort.Enabled = true;

            btn_Docfile.Enabled = true;
            btn_Taomang.Enabled = true;
            btn_Ngaunhien.Enabled = true;
            btn_Nhap.Enabled = true;
            txt_chiso.Enabled = true;
            txt_giatri.Enabled = true;
        }
        //Hàm tạo mảng
        public void Tao_mang()
        {
            if ((Spt < 2) || (Spt > 30))
            {
                lbl_A.Visible = false;
                MessageBox.Show("2 <= Số Phần Tử <= 30");

                this.txt_sophantu.Clear();
                Da_tao_mang = false;
                return;
            }

            #region Thiết lập thuộc tính node ứng với số phần tử
            switch (Spt)
            {
                case 30:
                case 29:
                case 28:
                case 27:
                case 26:
                    Kich_thuoc = 27;
                    Co_chu = 10;
                    Khoang_cach = 6;
                    Canh_le = (1024 - Kich_thuoc * Spt - Khoang_cach * (Spt - 1)) / 2;
                    break;
                case 25:
                case 24:
                case 23:
                case 22:
                case 21:
                    Kich_thuoc = 30;
                    Co_chu = 13;
                    Khoang_cach = 10;
                    Canh_le = (1024 - Kich_thuoc * Spt - Khoang_cach * (Spt - 1)) / 2;
                    break;
                case 20:
                case 19:
                    Kich_thuoc = 40;
                    Co_chu = 18;
                    Khoang_cach = 5;
                    Canh_le = (1024 - Kich_thuoc * Spt - Khoang_cach * (Spt - 1)) / 2;
                    break;
                case 18:
                case 17:
                case 16:
                    Kich_thuoc = 40;
                    Co_chu = 18;
                    Khoang_cach = 10;
                    Canh_le = (1024 - Kich_thuoc * Spt - Khoang_cach * (Spt - 1)) / 2;
                    break;
                case 15:
                case 14:
                case 13:
                case 12:
                case 11:
                    Kich_thuoc = 40;
                    Co_chu = 18;
                    Khoang_cach = 18;
                    Canh_le = (1024 - Kich_thuoc * Spt - Khoang_cach * (Spt - 1)) / 2;
                    break;
                case 10:
                case 9:
                case 8:
                case 7:
                case 6:
                case 5:
                case 4:
                case 3:
                case 2:
                    Kich_thuoc = 50;
                    Co_chu = 25;
                    Khoang_cach = 40;
                    Canh_le = (1024 - Kich_thuoc * Spt - Khoang_cach * (Spt - 1)) / 2;
                    break;
            }
            #endregion
            #region Tạo các mảng dữ liệu
            Chi_so = new Label[Spt];
            a = new int[Spt];
            Node = new TextBox[Spt];
            #endregion
            //Dán nhãn mảng a
            lbl_A.Width = Kich_thuoc;
            lbl_A.Height = Kich_thuoc;
            lbl_A.Location = new Point(Canh_le - (Kich_thuoc), 250);
            lbl_A.Font = new System.Drawing.Font("Arial", Co_chu, FontStyle.Bold);
            lbl_A.Visible = true;
            #region Tạo node và chỉ số
            for (i = 0; i < Spt; i++)
            {
                //node
                a[i] = i;
                Node[i] = new TextBox();
                Node[i].Multiline = true;
                Node[i].Text = a[i].ToString();
                Node[i].TextAlign = HorizontalAlignment.Center;
                Node[i].Width = Kich_thuoc;
                Node[i].Height = Kich_thuoc;
                Node[i].Location = new Point(Canh_le + (Kich_thuoc + Khoang_cach) * i , 250);
                Node[i].BackColor = Color.OrangeRed;
                Node[i].ForeColor = Color.White;
                Node[i].Font = new Font(this.Font, FontStyle.Bold);
                Node[i].Font = new System.Drawing.Font("Arial", Co_chu, FontStyle.Bold);
                Node[i].ReadOnly = true;
                this.Controls.Add(Node[i]);
                //chỉ số
                Chi_so[i] = new Label();
                Chi_so[i].TextAlign = ContentAlignment.MiddleCenter;
                Chi_so[i].Text = i.ToString();
                Chi_so[i].Width = Kich_thuoc;
                Chi_so[i].Height = Kich_thuoc;
                Chi_so[i].ForeColor = Color.Azure;
                Chi_so[i].Location = new Point(Canh_le + (Kich_thuoc + Khoang_cach) * i, 340 + 3 * Kich_thuoc);
                if (Spt <= 10)
                {
                    Chi_so[i].Font = new System.Drawing.Font("Arial", Co_chu - 10, FontStyle.Regular);
                }
                else
                {
                    Chi_so[i].Font = new System.Drawing.Font("Arial", Co_chu, FontStyle.Regular);
                }
                this.Controls.Add(Chi_so[i]);
                Da_tao_mang = true; //Xác nhận đã tạo mảng
                //Cho phép các nút điều khiển có tác dụng khi đã tạo mảng
                btn_Sapxep.Enabled = true;
                btn_Ngaunhien.Enabled = true;
                btn_Nhap.Enabled = true;

            }
            #endregion
        }
        //Hàm xóa mảng
        public void Xoa_mang()
        {
            btn_Nhap.Enabled = false;
            btn_Ngaunhien.Enabled = false;
            btn_Sapxep.Enabled = false;
            if (Da_tao_mang == true)
            {
                for (i = 0; i < Spt; i++)
                {
                    this.Controls.Remove(Node[i]);
                    this.Controls.Remove(Chi_so[i]);

                }
            }
        }
        //Hàm dừng toàn bộ chương trình
        public void Play_or_Stop()
        {
            while (KT_tam_dung == true)
            {
                Application.DoEvents();
            }
        }
        //Hàm Tạm dừng
        public void Tam_dung()
        {
            if (Sap_xep_tung_buoc == true)
            {
                KT_tam_dung = true;
                btn_Dung.Enabled = false;
                Play_or_Stop();
            }

        }
        //Hàm đặt màu cho Node
        public void Dat_mau_node(Control t, System.Drawing.Color Mau_nen, System.Drawing.Color Mau_chu)
        {
            t.BackColor = Mau_nen;
            t.ForeColor = Mau_chu;
            t.Refresh();
        }
        #endregion
        #region QUICK SORT
        void QuickSort(int left, int right)
        {
            int i, j, x, cs_x;


            //Status 01
            lbl_status_01.Text = "Phân hoạch đoạn [" + left + "," + right + "]";
            
            //đặt mũi tên chỉ left
            Mui_ten_xanh_len_1.Location = new Point((Canh_le + (Kich_thuoc + Khoang_cach) * left) + (Kich_thuoc / 2) - 30, Node[left].Location.Y + 2 * Kich_thuoc + 5);
            Mui_ten_xanh_len_1.Text = "L = " + left;
            Mui_ten_xanh_len_1.Visible = true;
            Mui_ten_xanh_len_1.Refresh();
            //đặt mũi tên chỉ Right
            Mui_ten_xanh_len_2.Location = new Point((Canh_le + (Kich_thuoc + Khoang_cach) * right) + (Kich_thuoc / 2) - 30, Node[right].Location.Y + 2 * Kich_thuoc + 5);
            Mui_ten_xanh_len_2.Text = "R = " + right;
            Mui_ten_xanh_len_2.Visible = true;
            Mui_ten_xanh_len_2.Refresh();
            //
            x = a[(left + right) / 2];
            cs_x = (left + right) / 2;
            lblKhoa.Text = "Khóa [ " + cs_x + " ]  = " + x;
            long k = 0;
            while (k < a.Length)
            {
                if (k >= left && k <= right)
                {
                    Dat_mau_node(Node[k], Color.White, Color.Black);
                    k++;
                }
                else
                {
                    Dat_mau_node(Node[k], Color.OrangeRed, Color.White);
                    k++;
                }
            }
            //Thiết lập vị trí của x
            Mui_ten_do_len.Visible = true;
            Mui_ten_do_len.Location = new Point((Canh_le + (Kich_thuoc + Khoang_cach) * cs_x) + (Kich_thuoc / 2) - 30, Node[cs_x].Location.Y + 2 * Kich_thuoc + 65);
            Mui_ten_do_len.Text = "X";
            Mui_ten_do_len.Refresh();
            //
            //Đặt màu nút x                    
            //
            i = left; j = right;
            //Thiết lập mũi tên chỉ i
            Mui_ten_xanh_xuong_1.Visible = true;
            Mui_ten_xanh_xuong_1.Location = new Point((Canh_le + (Kich_thuoc + Khoang_cach) * i) + (Kich_thuoc / 2) - 30, Node[i].Location.Y - Kich_thuoc - 55);
            Mui_ten_xanh_xuong_1.Text = "i=" + i;
            Mui_ten_xanh_xuong_1.Refresh();
            //Thiết lập mũi tên chỉ j
            Mui_ten_xanh_xuong_2.Visible = true;
            Mui_ten_xanh_xuong_2.Location = new Point((Canh_le + (Kich_thuoc + Khoang_cach) * j) + (Kich_thuoc / 2) - 30, Node[j].Location.Y - Kich_thuoc - 55);
            Mui_ten_xanh_xuong_2.Text = "j=" + j;
            Mui_ten_xanh_xuong_2.Refresh();
            //
            do
            {
                //Hiệu ứng so sánh
                lbl_status_02.Text = "So_Sanh(a[" + i + "], a[x])";
                Tre(40 * Toc_do);
                while (a[i] < x)
                {
                    i++;
                    //Thiết lập mũi tên chỉ i
                    Mui_ten_xanh_xuong_1.Visible = true;
                    Mui_ten_xanh_xuong_1.Location = new Point((Canh_le + (Kich_thuoc + Khoang_cach) * i) + (Kich_thuoc / 2) - 30, Node[i].Location.Y - Kich_thuoc - 55);
                    Mui_ten_xanh_xuong_1.Text = "i=" + i;
                    Mui_ten_xanh_xuong_1.Refresh();
                    //
                    //Hiệu ứng so sánh
                    lbl_status_02.Text = "So_Sanh(a[" + i + "], a[x])";
                    Tre(40 * Toc_do);
                }
                //Hiệu ứng so sánh
                lbl_status_02.Text = "So_Sanh(a[" + j + "], a[x])";
                Tre(40 * Toc_do);
                while (a[j] > x)
                {
                    j--;
                    //Thiết lập mũi tên chỉ j
                    Mui_ten_xanh_xuong_2.Visible = true;
                    Mui_ten_xanh_xuong_2.Location = new Point((Canh_le + (Kich_thuoc + Khoang_cach) * j) + (Kich_thuoc / 2) - 30, Node[j].Location.Y - Kich_thuoc - 55);
                    Mui_ten_xanh_xuong_2.Text = "j=" + j;
                    Mui_ten_xanh_xuong_2.Refresh();
                    //
                    //Hiệu ứng so sánh
                    lbl_status_02.Text = "So_Sanh(a[" + j + "], a[x])";
                    Tre(40 * Toc_do);
                }
                if (i <= j)
                {
                    //status hoán vị
                    lbl_status_02.Text = "Hoan_Vi(a[" + i + "], a[" + j + "])";
                    Tre(40 * Toc_do);
                    Hoan_vi(ref a[i], ref a[j]);
                    //Tìm vị trí mới của x
                    if (i == cs_x)
                    {
                        cs_x = j;
                    }
                    else if (j == cs_x)
                    {
                        cs_x = i;
                    }

                    Application.DoEvents();
                    this.Invoke((MethodInvoker)delegate
                    {
                        Hoan_Vi_Node(Node[i], Node[j]);
                    });
                    Tam_dung();
                    Hoan_Tri_Node(i, j);
                    //Thiết lập vị trí của x
                    Mui_ten_do_len.Visible = true;
                    Mui_ten_do_len.Location = new Point((Canh_le + (Kich_thuoc + Khoang_cach) * cs_x) + (Kich_thuoc / 2) - 30, Node[cs_x].Location.Y + 2 * Kich_thuoc + 55);
                    Mui_ten_do_len.Text = "X = " + ((left + right) / 2);
                    Mui_ten_do_len.Refresh();
                    i++; j--;
                }
            } while (i <= j);
            //Đặt màu nút x
            if (j == 0)
            {
                Dat_mau_node(Node[j], Color.LawnGreen, Color.Black);
            }
            if (i == Spt - 1)
            {
                Dat_mau_node(Node[j], Color.LawnGreen, Color.Black);
            }

            if (left < j)
            {
                QuickSort(left, j);
            }
            if (i < right)
            {
                 
                QuickSort(i, right);
            }

        }
        #endregion
        #region Phương Thức Thực Hiện
        private void btn_Docfile_Click_1(object sender, EventArgs e)
        {
            //Gọi hàm xóa mảng
            Xoa_mang();
            //Đọc file
            StreamReader Re = File.OpenText("TEST.txt");
            string input = null;
            int i = 0;
            int kt = 0;
            while ((kt < 1) && ((input = Re.ReadLine()) != null))
            {
                Spt = Convert.ToInt32(input);
                kt++;
            }
            //Gọi hàm tạo mảng
            Tao_mang();
            while (((input = Re.ReadLine()) != null) && (i < Spt))
            {

                Node[i].BackColor = Color.OrangeRed; // đặt lại màu cho mảng ngẫu nhiên
                Node[i].ForeColor = Color.White;
                a[i] = Convert.ToInt32(input);
                Node[i].Text = a[i].ToString();
                i++;
            }
            Re.Close();
        }

        private void btn_Taomang_Click(object sender, EventArgs e)
        {
            //Gọi hàm xóa mảng
            Xoa_mang();
            this.txt_sophantu.Focus();
            this.txt_sophantu.SelectAll();
            try
            {
                Spt = Convert.ToInt32(txt_sophantu.Text);
            }
            catch
            {
                MessageBox.Show("Số phần tử vừa nhập vào không hợp lệ!");
                this.txt_sophantu.Clear();
                return;
            }
            //gọi hàm tạo mảng
            Tao_mang();
        }

        private void btn_Ngaunhien_Click_1(object sender, EventArgs e)
        {
            btn_Sapxep.Enabled = true;
            Random r = new Random();
            for (i = 0; i < Spt; i++)
            {
                Node[i].BackColor = Color.OrangeRed; // đặt lại màu cho mảng ngẫu nhiên
                Node[i].ForeColor = Color.White;
                a[i] = r.Next(100);
                Node[i].Text = a[i].ToString();
            }
        }

        private void btn_Nhap_Click_1(object sender, EventArgs e)
        {
            Boolean KTra = true;
            int giatri;
            try
            {
                i = Convert.ToInt32(txt_chiso.Text);
            }
            catch
            {
                MessageBox.Show("Chỉ số nhập vào không hợp lệ!");
                return;
            }
            if (i > Spt - 1)
            {
                MessageBox.Show("Không có phần tử thứ  " + i);
                return;
            }
            try
            {
                giatri = Convert.ToInt32(txt_giatri.Text);
            }
            catch
            {
                MessageBox.Show("Giá trị nhập vào không hợp lệ!");
                return;
            }
            if ((giatri < 0) || (giatri > 100))
            {
                MessageBox.Show("0 <= Giá trị nhập vào < 100");
                this.txt_giatri.Clear();
                KTra = false;
            }
            if (KTra == true)
            {
                for (int j = 0; j < Spt; j++)
                {
                    Node[j].BackColor = Color.OrangeRed; // đặt lại màu cho mảng không thứ tự
                    Node[j].ForeColor = Color.White;
                }
                a[i] = giatri;
                Node[i].Text = a[i].ToString();
                Chi_so[i].Text = i.ToString();
                //Đổi màu node khi nhận giá trị nhập vào
                Node[i].BackColor = Color.AliceBlue;
                Node[i].ForeColor = Color.Black;
                Node[i].Refresh();
                Thread.Sleep(1000);
                Node[i].BackColor = Color.OrangeRed;
                Node[i].ForeColor = Color.White;
                Node[i].Refresh();
                this.txt_giatri.Text = (giatri + 1).ToString();
                this.txt_chiso.Focus();
                this.txt_chiso.Text = (i + 1).ToString();
                this.txt_chiso.SelectAll();
            }
        }

        private void btn_Sapxep_Click(object sender, EventArgs e)
        {
            rad_quicksort.Enabled = false;
            //Cho phép các nút điều khiển
            btn_Dung.Enabled = true;
            btn_Chayhet.Enabled = true;
            if (chk_Tungbuoc.Checked == true)
            {
                btn_Ketiep.Enabled = true;
                Sap_xep_tung_buoc = true;
            }

            //Thiết lập các nút nhập liệu
            btn_Docfile.Enabled = false;
            btn_Taomang.Enabled = false;
            btn_Ngaunhien.Enabled = false;
            btn_Nhap.Enabled = false;
            txt_chiso.Enabled = false;
            txt_giatri.Enabled = false;

            #region QUICK SORT
            if (rad_quicksort.Checked == true)
            {
                Application.DoEvents();
                this.Invoke((MethodInvoker)delegate
                {
                    QuickSort(0, Spt - 1);
                });
                Hoan_thanh();
            }

            #endregion
        }

        private void Tmr_Thay_doi_toc_do_Tick(object sender, EventArgs e)
        {
            Toc_do = (Trb_Toc_do.Maximum - Trb_Toc_do.Value);
            lbl_Toc_do.Text = Trb_Toc_do.Value.ToString();
            if (Trb_Toc_do.Value == Trb_Toc_do.Maximum)
            {
                lbl_Toc_do.Text = "Max=10";
            }
            else if (Trb_Toc_do.Value == Trb_Toc_do.Minimum)
            {
                lbl_Toc_do.Text = "Min=0";
            }
        }

        private void btn_Dung_Click(object sender, EventArgs e)
        {
            btn_Chayhet.Focus();

            if (btn_Dung.Text == ";")
            {
                btn_Dung.Text = "4";
                KT_tam_dung = true;
                Play_or_Stop();
            }
            else
            {
                btn_Dung.Text = ";";
                KT_tam_dung = false;
            }
        }

        private void btn_Chayhet_Click(object sender, EventArgs e)
        {
            btn_Dung.Text = ";";
            chk_Tungbuoc.Checked = false;
            Sap_xep_tung_buoc = false;
            KT_tam_dung = false;
            btn_Dung.Enabled = true;
        }

        private void btn_Ketiep_Click(object sender, EventArgs e)
        {
            btn_Dung.Text = ";";
            Sap_xep_tung_buoc = true;
            chk_Tungbuoc.Checked = true;
            KT_tam_dung = false;
            btn_Dung.Enabled = true;
        }

        private void chk_Tungbuoc_CheckedChanged(object sender, EventArgs e)
        {
            if (chk_Tungbuoc.Checked == true)
            {
                btn_Ketiep.Enabled = true;
                Sap_xep_tung_buoc = true;
            }
            else
            {
                btn_Ketiep.Enabled = false;
                Sap_xep_tung_buoc = false;
            }
        }

        private void btn_Phongto_Click(object sender, EventArgs e)
        {
            Kthuoc_Code++;
            lst_Code.Font = new System.Drawing.Font("Arial", Kthuoc_Code, FontStyle.Bold);
        }

        private void btn_Thunho_Click(object sender, EventArgs e)
        {
            Kthuoc_Code--;
            lst_Code.Font = new System.Drawing.Font("Arial", Kthuoc_Code, FontStyle.Bold);
        }

        private void rad_quicksort_CheckedChanged(object sender, EventArgs e)
        {
            if (rad_quicksort.Checked == true)
            {
                lst_Code.Items.Clear();
                //Tải code của thuật toán Quick Sort vào Cửa sổ xem code
                lst_Code.Items.Add("void QuickSort(int a[], int left, int right)");
                lst_Code.Items.Add("     {");
                lst_Code.Items.Add("            int i, j, x;");
                lst_Code.Items.Add("            x = a[(left + right) / 2]; ");
                lst_Code.Items.Add("            i = left; j = right;");
                lst_Code.Items.Add("               do");
                lst_Code.Items.Add("                  {");
                lst_Code.Items.Add("                   while(a[i] < x) i++;");
                lst_Code.Items.Add("                   while(a[j] > x) j--;");
                lst_Code.Items.Add("                       if(i <= j)");
                lst_Code.Items.Add("                         { ");
                lst_Code.Items.Add("                           Swap(a[i], a[j]);");
                lst_Code.Items.Add("                           i++ ; j--;");
                lst_Code.Items.Add("                         }");
                lst_Code.Items.Add("                   }");
                lst_Code.Items.Add("               while(i <= j);");
                lst_Code.Items.Add("               if(left < j)");
                lst_Code.Items.Add("                   QuickSort(a, left, j);");
                lst_Code.Items.Add("               if(i < right)");
                lst_Code.Items.Add("                   QuickSort(a, i, right);");
                lst_Code.Items.Add("      }");
            }
        }

        private void Sort_FormClosing(object sender, FormClosingEventArgs e)
        {
            Environment.Exit(0);
        }
        #endregion
        #region Menu
        private void đọcFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            btn_Docfile_Click_1(sender, e);
        }

        private void tạoMảngToolStripMenuItem_Click(object sender, EventArgs e)
        {
            btn_Taomang_Click(sender, e);
        }

        private void ngẫuNhiênToolStripMenuItem_Click(object sender, EventArgs e)
        {
            btn_Ngaunhien_Click_1(sender, e);
        }

        private void phóngToToolStripMenuItem_Click(object sender, EventArgs e)
        {
            btn_Phongto_Click(sender, e);
        }

        private void thuNhỏToolStripMenuItem_Click(object sender, EventArgs e)
        {
            btn_Thunho_Click( sender, e);
        }

        private void sắpXếpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            btn_Sapxep_Click(sender,e);
        }

        private void kếtThúcToolStripMenuItem_Click(object sender, EventArgs e)
        {
            btn_Chayhet_Click(sender, e);
        }

        private void kếTiếpToolStripMenuItem_Click(object sender, EventArgs e)
        {
             btn_Ketiep_Click(sender, e);
        }

        private void tạmDừngToolStripMenuItem_Click(object sender, EventArgs e)
        {
            btn_Dung_Click(sender, e);
        }

        private void Menu_Thong_tin_Click(object sender, EventArgs e)
        {
            About frm_about = new About();
            frm_about.ShowDialog();
        }

        private void cáchSửDụngToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Help frm_help = new Help();
            frm_help.ShowDialog();
        }

        private void menu_Thoat_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }

        private void nhậpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            btn_Nhap_Click_1(sender, e);
        }
        #endregion
    }
}
