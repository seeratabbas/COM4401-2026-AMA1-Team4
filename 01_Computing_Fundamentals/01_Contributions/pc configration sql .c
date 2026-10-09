/* ============================================================
CREATE TABLES FIRST
============================================================ */

-- Table for employee roles
CREATE TABLE EmployeeRoles (
    RoleID VARCHAR(5) PRIMARY KEY,
    RoleName VARCHAR(100) NOT NULL,
    StaffCount INT,
    Tasks TEXT,
    PerformanceNeed TEXT,
    BudgetPerWorkstation DECIMAL(10,2)
);

-- Table for workstation builds
CREATE TABLE WorkstationBuilds (
    BuildID INT PRIMARY KEY,
    BuildName VARCHAR(150) NOT NULL,
    RoleID VARCHAR(5),
    FOREIGN KEY (RoleID) REFERENCES EmployeeRoles(RoleID)
);

-- Table for individual build items
CREATE TABLE BuildItems (
    ItemID INT PRIMARY KEY,
    BuildID INT,
    Category VARCHAR(50),
    ItemName VARCHAR(200),
    Cost DECIMAL(10,2),
    Justification TEXT,
    FOREIGN KEY (BuildID) REFERENCES WorkstationBuilds(BuildID)
);

-- Table for final recommendations
CREATE TABLE Recommendations (
    RoleID VARCHAR(5) PRIMARY KEY,
    RecommendationText TEXT,
    FOREIGN KEY (RoleID) REFERENCES EmployeeRoles(RoleID)
);

/* ============================================================
INSERT DATA INTO TABLES
============================================================ */

-- ===========================
-- EMPLOYEE ROLES
-- ===========================
INSERT INTO EmployeeRoles
(RoleID, RoleName, StaffCount, Tasks, PerformanceNeed, BudgetPerWorkstation)
VALUES
('R1', 'Administrative Assistant',
 3,
'answering phone calls, team video calls, replying to emails in outlook,recording and storing customer data word, Excel and Powerpoint','mid-range CPU with intergrated graphics, 16GB dual-channel RAM, 512GB NVMe SSD, full HD IPS monitor, webcam and Headset',950),

('R2', 'Project Manager',
 1,
 'Organises, plans and monitors day‑to‑day tasks to ensure deadlines, budgets and workloads are managed effectively. Uses spreadsheets, reports, emails and project management software to communicate with clients and team members. Requires fast multitasking, responsive performance, dual monitors, webcam and headset for professional communication.',
 'Responsive CPU performance, fast NVMe storage, 16GB DDR5 RAM, dual‑monitor workflow, reliable power, quiet cooling',
 1300),

('R3', 'Architect / CAD Designer',
 5,
 'CAD drawings, 3D modelling, BIM workflows, design reviews',
 'High CPU performance, dedicated GPU, fast NVMe storage, IPS display',
 2500),

('R4', '3D Visualisation Specialist',
 2,
 '3D modelling, visualisation, rendering, complex scenes, large assets and textures',
 'High-performance CPU, dedicated GPU, 64GB RAM, fast SSD storage and high-resolution 4K display',
 3750);

/* ============================================================
WORKSTATION BUILDS
============================================================ */
INSERT INTO WorkstationBuilds
(BuildID, BuildName, RoleID)
VALUES
(1, 'Admin Workstation Build', 'R1'),
(2, 'Project Manager Workstation Build', 'R2'),
(3, 'CAD Workstation Build (Intel)', 'R3'),
(4, '3D Visualisation Workstation Build (AMD)', 'R4');

/* ============================================================
BUILD ITEMS
============================================================ */

INSERT INTO BuildItems
(ItemID, BuildID, Category, ItemName, Cost, Justification)
VALUES

/* ===========================
ADMINISTRATIVE ASSISTANT WORKSTATION
=========================== */
(101, 1, 'CPU' ,'AMD Ryzen 5 5600G (cooler included)',154.99, '6 cores and 12 threads run Word, Excel and Teams at the same time; integrated graphics remove the need for a graphics card'),
(102, 1, 'Motherboard' , 'ASUS Prime B550M-A WIFI II mATX AM4 DDR4', 87.99, 'AM4 socket fits the 5600G; provides M.2 slot, HDMI port and Wi-Fi as a backup connection') ,
(103, 1, 'RAM' , 'Corsair Vengeance LPX 16GB (2x8GB) DDR4 3200 CL16' ,149.99 , '16GB for multitasking with Teams; two sticks enable dual-channel mode for the integrated graphics'),
(104, 1, 'GPU' , 'None - integrated graphics' , 0.00, 'Light office tasks only; a dedicated graphics card would add cost without improving performance') ,
(105, 1, 'Storage', 'Patriot P300 512GB M.2 NVMe PCIe Gen 3 SSD' , 68.99 , 'Much faster than an HDD; 512GB is enough because customer files are stored on the company server') ,
(106, 1, 'PSU' ,'MSI MAG A550BN 550W 80+ Bronze' , 40.60, '550W gives safe headroom above the 159W build; 80+ Bronze wastes less energy as heat'),
(107, 1, 'Case' , 'Kolink KLA-003 ATX Mid Tower', 17.99, 'All components fit, including the ATX PSU; simple office case'),
(108 ,1, 'CPU Cooler' , 'Included with CPU' , 0.00, 'stock cooler included a further cost'),
(109, 1, 'Monitor' , 'Philips 24E1N1100A 24-inch FHD IPS', 68.60, 'Full HD is enough for office tasks; IPS and LowBlue Mode reduce eye fatigue' ),
(110, 1, 'Headset' , 'Jabra Evolve 10 wired USB headset' , 23.95, 'Clear microphone for Teams calls and keeps sensitive customer data private'),
(111, 1, 'Webcam', 'Logitech C270 720p webcam', 19.89, '720p is enough because Teams adjusts video quality to bandwidth'),
(112, 1, 'Keyboard' , 'TECKNET wired keyboard and mouse set, UK QWERTY' ,18.99, 'Wired set is reliable with no batteries to run out'),
(113, 1, 'Mouse', 'Included with TECKNET keyboard set' , 0.00 , 'Mouse is part of the keyboard set, so there is no extra cost'),
(114, 1, 'Cables', 'UGREEN Cat6 Flat Ethernet cable 5m' , 5.05, 'Stable wired connection for video calls; Wi-Fi acts as a backup'),

/* ===========================
PROJECT MANAGER WORKSTATION
=========================== */

(201, 2, 'CPU', 'AMD Ryzen 5 7600', 154.00,
 'Fast multitasking performance with 6 cores and integrated Radeon graphics'),

(202, 2, 'Motherboard', 'Gigabyte B650M D3HP AX', 107.99,
 'Compatible AM5 platform with DDR5 support, WiFi, Bluetooth and dual‑display connectivity'),

(203, 2, 'RAM', 'ADATA Premier Black 16GB DDR5 (2×8GB)', 170.99,
 'High‑speed DDR5 memory for multitasking across spreadsheets, dashboards and project management apps'),

(204, 2, 'Storage', 'Kingston NV3 1TB PCIe 4.0 NVMe SSD', 128.99,
 'Fast NVMe storage for Windows, applications and project files'),

(205, 2, 'GPU', 'Integrated Radeon Graphics', 0.00,
 'Integrated GPU suitable for dual‑display office workflow'),

(206, 2, 'CPU Cooler', 'Thermalright Assassin X 120 Refined SE', 15.00,
 'Provides stable cooling during long multitasking sessions'),

(207, 2, 'PSU', 'EVGA SuperNOVA 550 GA 550W 80+ Gold', 206.57,
 'Reliable and efficient power delivery for business workloads'),

(208, 2, 'Case', 'Montech AIR 100 Lite', 34.99,
 'Provides airflow and protection for internal components'),

(209, 2, 'Operating System', 'Windows 11 Pro', 135.00,
 'Professional OS for business applications and project management software'),

(210, 2, 'Monitor', 'Pixio PX246 24-inch FHD 120Hz IPS', 89.99,
 'IPS display for spreadsheets, timelines and project documentation'),

(211, 2, 'Monitor', 'Pixio PX246 24-inch FHD 120Hz IPS', 89.99,
 'Second monitor for side‑by‑side workflow'),

(212, 2, 'Keyboard + Mouse', 'Dell KM5221W Wireless Keyboard & Mouse', 29.99,
 'Reliable daily input devices for office productivity'),

(213, 2, 'Webcam', 'NexiGo N60 1080p', 31.99,
 'Clear video quality for client meetings and team communication'),

(214, 2, 'Headset', 'Sades SA‑902‑B 7.1 Channel', 31.45,
 'Clear audio and microphone quality for professional online meetings'),

/* ===========================
CAD WORKSTATION
=========================== */

(301, 3, 'CPU', 'Intel Core i7-13700K', 415.00,
 'High single-core performance ideal for CAD geometry and regeneration'),

(302, 3, 'Motherboard', 'ASUS ROG Maximus Apex Z690 DDR5', 938.08,
 'Stable DDR5 platform with strong performance for professional workloads'),

(303, 3, 'RAM', 'Corsair Vengeance 32GB DDR5 6000MHz', 449.99,
 'Required for large BIM files and multi-application workflows'),

(304, 3, 'Storage', 'Crucial T705 1TB NVMe PCIe Gen5 SSD', 235.99,
 'Ultra-fast loading and saving of CAD/BIM project files'),

(305, 3, 'GPU', 'Gigabyte RTX 3060 12GB', 426.88,
 'Needed for 3D modelling, viewport rendering and visualisation'),

(306, 3, 'CPU Cooler', 'MSI MAG CORELIQUID E240 240mm AIO', 69.95,
 'Keeps Intel CPU cool during long CAD sessions'),

(307, 3, 'PSU', 'MSI MAG A650GL 650W Gold', 70.99,
 'Reliable power delivery for GPU workloads'),

(308, 3, 'Monitor', 'LG UltraGear 25-inch IPS FHD', 99.95,
 'IPS panel provides suitable colour reproduction for design work'),

(309, 3, 'Keyboard', 'Logitech K120 Wired Keyboard', 16.94,
 'Full-size keyboard suitable for drafting tasks'),

(310, 3, 'Mouse', 'Logitech M100 Wired Mouse', 5.98,
 'Provides precise control for CAD operations'),

(311, 3, 'Webcam', 'NexiGo 1080p HD Webcam', 31.99,
 'Used for remote client meetings and design reviews'),

(312, 3, 'Cables', 'UGREEN DisplayPort Cable + DDmall Cat8 Ethernet', 14.18,
 'Provides monitor connectivity and network connectivity'),

/* ===========================
3D VISUALISATION WORKSTATION
=========================== */

(401, 4, 'CPU', 'AMD Ryzen 9 7900X', 253.00,
 'High-performance processor suitable for demanding 3D visualisation, modelling and rendering workloads'),

(402, 4, 'Motherboard', 'ASUS TUF GAMING B850-PLUS WIFI', 159.99,
 'Provides a compatible AMD platform with suitable connectivity'),

(403, 4, 'GPU', 'Sparkle Intel Arc Pro B60 Passive 24GB GDDR6', 869.99,
 'Dedicated professional GPU with 24GB VRAM for complex workloads'),

(404, 4, 'RAM', 'Corsair Vengeance RGB 64GB DDR5 6000 CL30 White', 976.99,
 '64GB memory for complex 3D scenes and large assets'),

(405, 4, 'CPU Cooler', 'Corsair NAUTILUS Water 360mm RS ARGB Black', 33.04,
 '360mm liquid cooling for high-performance CPU'),

(406, 4, 'Storage', 'Western Digital Green SN350 2TB SSD M.2 NVMe PCIe 3.0', 213.74,
 '2TB NVMe storage for applications and large 3D assets'),

(407, 4, 'PSU', 'MSI MAG A850GL PCIE5 850W Fully Modular 80+ Gold', 99.99,
 '850W PSU suitable for high-performance workloads'),

(408, 4, 'Case', 'Montech HS02 ATX Mid Tower White', 24.98,
 'Supports ATX motherboard and large GPU'),

(409, 4, 'Monitor', 'ASUS ROG Swift OLED PG32UCDP 31.5-inch 4K 240Hz WOLED', 749.00,
 '4K resolution for detailed visualisation'),

(410, 4, 'Keyboard', 'Redragon K745 Wired Gasket RGB Gaming Keyboard', 43.99,
 'Full-size keyboard suitable for 3D applications'),

(411, 4, 'Mouse', 'Logitech M220 Wireless Mouse', 11.99,
 'Reliable mouse control for 3D applications');

/* ============================================================
RECOMMENDATIONS
============================================================ */

INSERT INTO Recommendations
(RoleID, RecommendationText)
VALUES
('R1', 'The Administrative Assistant workstation is designed for office tasks such as Word, Excel, Outlook and Teams video calls. The Ryzen 5 5600G with integrated graphics, 16GB dual-channel RAM and a 512GB NVMe SSD provide smooth multitasking without the cost of a graphics card. The total cost is £657.03 per workstation and £1,971.09 for three workstations, which is £578.91 under the £2,550.00 role budget.'),

('R2',
'The Project Manager workstation for is designed for fast multitasking, responsive performance and professional communication. The AMD Ryzen 5 7600 provides strong multi‑core performance with integrated graphics. The 16GB DDR5 RAM and NVMe SSD ensure smooth operation across spreadsheets, dashboards, reports and project management software. Dual Pixio 24-inch IPS monitors support side‑by‑side workflow. The webcam and headset provide clear communication for online meetings. The final cost per workstation is £1,226.94, which is under the £1,250 allocation and below the £1,300 maximum limit.'),

('R3',
'The CAD workstation is designed to meet the performance requirements of architectural CAD, BIM and 3D modelling workloads. The dedicated GPU, high-performance CPU and fast NVMe storage support demanding design tasks.'),

('R4',
'The 3D Visualisation Specialist workstation is designed for demanding 3D modelling, visualisation and rendering workloads. The AMD Ryzen 9 9950X3D CPU, dedicated 24GB GPU and 64GB RAM provide high-performance processing and graphics capability. The 2TB NVMe SSD provides storage for large projects and assets, while the 4K display provides detailed visual output. The current BuildCores configuration is £3,760.64, which is £160.64 above the £3,600 per-workstation allocation, so the final build should be reviewed for an appropriate cost compromise before submission.');

/* ============================================================
SHOW OUTPUT
============================================================ */

SELECT * FROM EmployeeRoles;
SELECT * FROM WorkstationBuilds;
SELECT * FROM BuildItems;
SELECT * FROM Recommendations;
/* ============================================================
COMPLEX QUERIES SECTION
============================================================ */

-- 1. Total cost per workstation build
SELECT 
    W.BuildID,
    W.BuildName,
    SUM(B.Cost) AS TotalCost
FROM WorkstationBuilds W
JOIN BuildItems B ON W.BuildID = B.BuildID
GROUP BY W.BuildID, W.BuildName;

-- 2. Compare total cost against budget for each role
SELECT 
    ER.RoleID,
    ER.RoleName,
    ER.BudgetPerWorkstation,
    SUM(BI.Cost) AS TotalCost,
    (SUM(BI.Cost) - ER.BudgetPerWorkstation) AS Difference,
    CASE 
        WHEN SUM(BI.Cost) <= ER.BudgetPerWorkstation THEN 'UNDER BUDGET'
        ELSE 'OVER BUDGET'
    END AS BudgetStatus
FROM EmployeeRoles ER
JOIN WorkstationBuilds WB ON ER.RoleID = WB.RoleID
JOIN BuildItems BI ON WB.BuildID = BI.BuildID
GROUP BY ER.RoleID, ER.RoleName, ER.BudgetPerWorkstation;

-- 3. Full workstation summary for each role
SELECT 
    ER.RoleID,
    ER.RoleName,
    ER.Tasks,
    ER.PerformanceNeed,
    ER.BudgetPerWorkstation,
    WB.BuildName,
    BI.ItemName,
    BI.Category,
    BI.Cost,
    BI.Justification
FROM EmployeeRoles ER
JOIN WorkstationBuilds WB ON ER.RoleID = WB.RoleID
JOIN BuildItems BI ON WB.BuildID = BI.BuildID
ORDER BY ER.RoleID, BI.Category;

-- 4. Most expensive component in each workstation
SELECT 
    WB.BuildName,
    BI.ItemName,
    BI.Category,
    BI.Cost
FROM BuildItems BI
JOIN WorkstationBuilds WB ON BI.BuildID = WB.BuildID
WHERE BI.Cost = (
    SELECT MAX(Cost) FROM BuildItems WHERE BuildID = BI.BuildID
);

-- 5. Count number of items in each workstation
SELECT 
    WB.BuildName,
    COUNT(*) AS NumberOfItems
FROM WorkstationBuilds WB
JOIN BuildItems BI ON WB.BuildID = BI.BuildID
GROUP BY WB.BuildName;

-- 6. Show all items costing more than £200
SELECT * FROM BuildItems
WHERE Cost > 200
ORDER BY Cost DESC;
