typedef enum
{
    VMW_IPC_TYPE_UNDEFINED = 0,
    VMW_IPC_TYPE_BOOL,
    VMW_IPC_TYPE_BOOLEAN,
    VMW_IPC_TYPE_UINT16,
    VMW_IPC_TYPE_INT16,
    VMW_IPC_TYPE_UINT32,
    VMW_IPC_TYPE_INT32,
    VMW_IPC_TYPE_UINT64,
    VMW_IPC_TYPE_INT64,
    VMW_IPC_TYPE_STRING,
    VMW_IPC_TYPE_WSTRING,
    VMW_IPC_TYPE_BLOB_SIZE,
    VMW_IPC_TYPE_BLOB
} VMW_IPC_TYPE;

typedef union _VMW_DATA_SPEC_
{
    PVOID pVoid;
    PBYTE pByte;
    PUINT16 pUint16;
    PINT16 pInt16;
    PUINT32 pUint32;
    PINT32 pInt32;
    PUINT64 pUint54;
    PINT64 iInt64;
    PSTR pString;
    PWSTR pWString;
    PBOOL pBool;
    PBOOLEAN pBoolean;
} VMW_DATA_SPEC, *PVMW_DATA_SPEC;

typedef struct _VMW_TYPE_SPEC_
{
    PSTR pszName;
    VMW_IPC_TYPE type;
    VMW_DATA_SPEC data;
}VMW_TYPE_SPEC, *PVMW_TYPE_SPEC;

#define ADD_CERT_REQUEST_PARAMS \
{\
    {\
        "Store Type",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Alias",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Certificate",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Private Key",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Auto Refresh",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define CREATE_STORE_REQUEST_PARAMS \
{\
    {\
      "Store Name",\
     VMW_IPC_TYPE_WSTRING,\
     {NULL}\
    },\
    {\
      "Password",\
      VMW_IPC_TYPE_WSTRING,\
      {NULL}\
    }\
}

#define DELETE_STORE_REQUEST_PARAMS \
{\
    {\
        "Store Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
}

#define RESPONSE_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define OPEN_STORE_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Store Handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    }\
}

#define PERMISSIONS_SET_INPUT_PARAMS \
{\
    {\
        "Store handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Handle Size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    },\
    {\
        "User Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Desired Access",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define PERMISSIONS_GET_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Owner Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Permissions Blob",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Permissions Blob Size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    }\
}

#define PERMISSIONS_SET_INPUT_SERVER_PARAMS \
{\
    {\
        "Store handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Handle size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    },\
    {\
        "User Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Desired Access",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define CHANGE_OWNER_INPUT_PARAMS \
{\
    {\
        "Store handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store handle size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    },\
    {\
        "User Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define PERMISSIONS_GET_INPUT_PARAMS \
{\
    {\
        "Store handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Handle size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    }\
}

#define ADD_ENTRY_INPUT_PARAMS \
{\
    {\
        "Store Handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Handle Size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    },\
    {\
        "Entry Type",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Alias",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Certificate",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Private Key",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Password",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Auto Refresh",\
        VMW_IPC_TYPE_BOOLEAN,\
        {NULL}\
    }\
}

#define DELETE_ENTRY_INPUT_PARAMS \
{\
    {\
        "Store Handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
      },\
    {\
        "Store Handle Size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    },\
    {\
        "Alias",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}\

#define BEGIN_ENUM_INPUT_PARAMS \
{\
    {\
        "Store Handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Handle Size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    },\
    {\
        "Entry Count",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Info Level",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define BEGIN_ENUM_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Limit",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Enum Context",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    }\
}

#define GET_ENTRY_BY_ALIAS_INPUT_PARAMS \
{\
    {\
        "Store Handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Handle Size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL},\
    },\
    {\
        "Alias",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL},\
    },\
    {\
        "Info Level",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define GET_ENTRY_BY_ALIAS_OUTPUT_PARAMS \
{\
    {\
        "Result Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Entry Type",\
        VMW_IPC_TYPE_UINT32,\
        {NULL},\
    },\
    {\
        "Date",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Certificate",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_KEY_BY_ALIAS_INPUT_PARAMS \
{\
    {\
        "Store Handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Handle size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    },\
    {\
        "Alias",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Password",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_KEY_BY_ALIAS_OUTPUT_PARAMS \
{\
    {\
        "Result Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
      },\
      {\
        "Key",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define ENUM_STORE_OUTPUT_PARAMS \
{\
    {\
        "Result Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Store Array",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Array Blob Size",\
      VMW_IPC_TYPE_BLOB_SIZE,\
      {NULL}\
    }\
}

#define ENUM_ENTRIES_INPUT_PARAMS \
{\
    {\
        "Enum Context",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Enum Context Size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    }\
}

#define ENUM_ENTRIES_OUTPUT_PARAMS \
{\
    {\
        "Result Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Entries Array Blob",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Entries Array size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    },\
    {\
        "EnumHandleBlob",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "EnumHandleSize",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
  }\
}

#define GET_ENTRY_COUNT_INPUT_PARAMS \
{\
    {\
        "Store Handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Handle size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    }\
}

#define GET_ENTRY_COUNT_OUTPUT_PARAMS \
{\
    {\
        "Result Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Count",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define CLOSE_STORE_REQUEST_PARAMS \
{\
    {\
        "Store Handle",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Store Handle Size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    }\
}

#define END_ENUM_REQUEST_PARAMS \
{\
    {\
        "Enum Context",\
        VMW_IPC_TYPE_BLOB,\
        {NULL}\
    },\
    {\
        "Enum Handle Size",\
        VMW_IPC_TYPE_BLOB_SIZE,\
        {NULL}\
    }\
}

#define GET_STATUS_INPUT_PARAMS \
{\
    {\
        "Status",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
}

#define GET_STATUS_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Status",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define GET_DOMAIN_NAME_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Domain Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define SET_DOMAIN_NAME_INPUT_PARAMS \
{\
    {\
        "Domain Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_DOMAIN_STATE_INPUT_PARAMS \
{\
    {\
        "Domain State",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define GET_DOMAIN_STATE_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Domain State",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define GET_LDU_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "LDU",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define SET_LDU_INPUT_PARAMS \
{\
    {\
        "LDU",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define SET_RHTTPPROXY_PORT_INPUT_PARAMS \
{\
    {\
        "RHTTPProxy Port",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define SET_DC_PORT_INPUT_PARAMS \
{\
    {\
        "DC Port",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    }\
}

#define GET_CM_LOCATION_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "CM Location",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_LS_LOCATION_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "LS Location",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_DC_NAME_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "DC Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_MACHINE_ACCOUNT_INFO_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Account",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Password",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define SET_DC_NAME_INPUT_PARAMS \
{\
    {\
        "Domain Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_SITE_GUID_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Site GUID",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_MACHINE_ID_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Machine ID",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define SET_MACHINE_ID_INPUT_PARAMS \
{\
    {\
        "Machine ID",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define PROMOTE_VMDIR_INPUT_PARAMS \
{\
  {\
    "Server Name",\
    VMW_IPC_TYPE_WSTRING,\
    {NULL}\
  },\
  {\
    "Domain Name",\
    VMW_IPC_TYPE_WSTRING,\
    {NULL}\
  },\
  {\
    "User Name",\
    VMW_IPC_TYPE_WSTRING,\
    {NULL}\
  },\
  {\
    "Password",\
    VMW_IPC_TYPE_WSTRING,\
    {NULL}\
  },\
  {\
    "Site Name",\
    VMW_IPC_TYPE_WSTRING,\
    {NULL}\
  },\
  {\
    "Partner Host Name",\
    VMW_IPC_TYPE_WSTRING,\
    {NULL}\
  }\
}

#define DEMOTE_VMDIR_INPUT_PARAMS \
{\
  {\
    "Server Name",\
    VMW_IPC_TYPE_WSTRING,\
    {NULL}\
  },\
  {\
    "User Name",\
    VMW_IPC_TYPE_WSTRING,\
    {NULL}\
  },\
  {\
    "Password",\
    VMW_IPC_TYPE_WSTRING,\
    {NULL}\
  }\
}

#define SET_DC_NAME_INPUT_PARAMS \
{\
    {\
        "Domain Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_SITE_GUID_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Site GUID",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_MACHINE_ID_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Machine ID",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define SET_MACHINE_ID_INPUT_PARAMS \
{\
    {\
        "Machine ID",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define PROMOTE_VMDIR_INPUT_PARAMS \
{\
    {\
        "Server Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Domain Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "User Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Password",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Site Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Partner Host Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define DEMOTE_VMDIR_INPUT_PARAMS \
{\
    {\
        "Server Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "User Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Password",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define JOIN_VMDIR_INPUT_PARAMS \
{\
    {\
        "Server Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "User Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Password",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "MachineName",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Domain Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Organizational Unit",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define LEAVE_VMDIR_INPUT_PARAMS \
{\
    {\
        "Server Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "User Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Password",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define JOIN_AD_INPUT_PARAMS \
{\
    {\
        "User Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Password",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "DomainName",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Org Unit",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define LEAVE_AD_INPUT_PARAMS \
{\
    {\
        "User Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Password",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define QUERY_AD_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "Computer",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Domain",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Distinguished Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    },\
    {\
        "Netbios Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define FORCE_REPLICATION_INPUT_PARAMS \
{\
    {\
        "Server Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_PNID_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "PNID",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define SET_PNID_INPUT_PARAMS \
{\
    {\
        "PNID",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define GET_CA_PATH_OUTPUT_PARAMS \
{\
    {\
        "Return Code",\
        VMW_IPC_TYPE_UINT32,\
        {NULL}\
    },\
    {\
        "CA Path",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}

#define SET_CA_PATH_INPUT_PARAMS \
{\
    {\
        "Domain Name",\
        VMW_IPC_TYPE_WSTRING,\
        {NULL}\
    }\
}
